// find lexogeraphically next greater element if it exists or else print no answer
string biggerIsGreater(string w)
{
    // next greater element
    int i, n = w.size();
    // find the first element such that a[i] < a[i+1] else return reverse of the string
    for (i = n - 2; i >= 0; i--)
    {
        if (w[i] < w[i + 1])
            break;
    }
    if (i == -1)
    {
        reverse(w.begin(), w.end());
        return "no answer";
    }

    // now find the first element from the back which is greater than
    int j;
    for (j = n - 1; j > i; j--)
    {
        if (w[j] > w[i])
            break;
    }
    swap(w[i], w[j]);
    reverse(w.begin()+i+1, w.end());
    return w;
}