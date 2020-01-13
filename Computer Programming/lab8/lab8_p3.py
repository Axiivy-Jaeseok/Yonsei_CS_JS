# define the function resetValues
def resetValues(L, threshold):
    """ This function is reset the values in L.
        The function get list L and number threshold.
        And It makes new list 'Result'.
        If the values in L is larger than threshold,
        function replaces the values to zero."""

# define Result
    Result = []

# finding values that are satisfied the condition
    for i in range(0, len(L)):
        if L[i] > threshold:
            Result.append(0)

    return Result

    
