#!/usr/bin/env python3

import math
from time import sleep
from dronekit import connect, VehicleMode, LocationGlobalRelative, Command
from pymavlink import mavutil

if __name__ == "__main__":
    vehicle = connect("udp:127.0.0.1:14550", wait_ready=True)

    while not vehicle.is_armable:
        sleep(1)

    vehicle.mode = VehicleMode('GUIDED')
    while not vehicle.armed:
        vehicle.armed = True
        sleep(1)

    alt = 10
    radius = 0.0001

    lat = vehicle.location.global_relative_frame.lat
    lon = vehicle.location.global_relative_frame.lon

    vehicle.simple_takeoff(alt)

    while True:
        if vehicle.location.global_relative_frame.alt >= alt * 0.95:
            break
        sleep(1)

    points = 30        # points in the circle we draw
    loops = 2 * points # do two loop
    coords = []
    for i in range(0, loops):
        degrees = (i/points)*360
        radians = (math.pi/180)*degrees
        x = lat + radius * math.cos(radians)
        y = (lon + radius * math.sin(radians))
        coords.append((x,y))

    cmds = vehicle.commands
    cmds.clear()

    for lat,lon in coords:
        point = LocationGlobalRelative(lat,lon,alt)
        cmds.add(Command( 0, 0, 0, mavutil.mavlink.MAV_FRAME_GLOBAL_RELATIVE_ALT, mavutil.mavlink.MAV_CMD_NAV_WAYPOINT, 0, 0, 0, 0, 0, 0, lat, lon, alt))

    cmds.upload()

    vehicle.mode = VehicleMode("AUTO")
    sleep(1)

    while True:
        nextwaypoint=vehicle.commands.next
        sleep(1)