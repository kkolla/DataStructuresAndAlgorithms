/*
 * Given interfaces that help getting a list out of the NestedInteger interface.
 */
public int depthSum_ (int level, List<NestedInteger> input)
{
    //Implementation here
    // traverse the list, and add the numbers, sum = level * (array[item])

    // iterator to iterate through the list
    int sum = 0;
    for (list<NestedInteger>::iterator it = input.begin(); it != input.end(); ++it)
    {
        if ((*it).isInteger()) {
            sum += ((*it).getInteger() * level);
        } else (){
            sum += depthSum_(level+1, (*it).getList())
        }
    }
    return sum;
}

public int depthSum (List<NestedInteger> input)
{
    if (input == NULL) {
        return 0;
    }
    return depthSum_(1, input);
}

/**
 * This is the interface that represents nested lists.
 * You should not implement it, or speculate about its implementation.
 */
public interface NestedInteger
{
    /** @return true if this NestedInteger holds a single integer, rather than a nested list */
    boolean isInteger();

    /** @return the single integer that this NestedInteger holds, if it holds a single integer
     * Return null if this NestedInteger holds a nested list */
    Integer getInteger();

    /** @return the nested list that this NestedInteger holds, if it holds a nested list
     * Return null if this NestedInteger holds a single integer */
    List<NestedInteger> getList();
}
