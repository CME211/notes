# Counting coins

Write a Python function to make change given a set of coins and a total amount.
The overall goal is to minimize the number of coins for the given total.  The
function prototype could be:

```py
def count_coins(total, coins):
    """Make change for total amount given set of coins
    
    Inputs:
      total: total amount for which one desires change
      coins: set of coins
    
    Returns a dictionary where keys are the coin value and the values are the count
    of that coin type.
    """
    pass
```

## Example 1

The normal coins that we use could be represented by the set: `{25,10,5,1}`.

```
count_coins(30,{25,10,5,1})
```

Could return:

```
{25:1,10:0,5:1,1:0}
```

## Example 2

```
count_coins(30,{25,10,5,1})
```

Could return:

```
{25:1, 10:0, 5:1, 1:0}
```

## Example 2

```
count_coins(17,{25,10,5,1})
```

Could return:

```
{25:0, 10:1,5:1,1:2}
```

## Example 3

Let's change our coin set to: `{4, 3, 1}`

What about:

```
count_coins(6, {4, 3, 1})
```

What would your algorithm return?  Is that the minimum number of coins?  How
might we minimize the number of coins.
