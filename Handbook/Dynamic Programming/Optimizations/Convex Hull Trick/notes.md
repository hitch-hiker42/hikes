# Notes:

## 1. Predicates:

### Non-increasing slope:
* Minimum Query: **remove**(end(hull)[-2], end(hull)[-1], l);
* Maximum Query: **remove**(l, end(hull)[-1], end(hull)[-2]);

### Non-decreasing slope:
* Minimum Query: **remove**(l, end(hull)[-1], end(hull)[-2]);
* Maximum Query: **remove**(end(hull)[-2], end(hull)[-1], l);

## 2. Ternary Searches:

* Minimum Query:
```cpp
auto query(int x) {
    line result = {0, 0};
    int lo = 0, hi = hull.size() - 1;
    while(lo <= hi) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        int y1 = hull[mid1].f(x), y2 = hull[mid2].f(x);
        if(y1 <= y2) result = hull[mid1], hi = mid2 - 1;
        else result = hull[mid2], lo = mid1 + 1;
    }
    return result;
}
```

* Maximum Query:

```cpp
auto query(int x) {
    line result = {0, 0};
    int lo = 0, hi = hull.size() - 1;
    while(lo <= hi) {
        int mid1 = lo + (hi - lo) / 3;
        int mid2 = hi - (hi - lo) / 3;
        int y1 = hull[mid1].f(x), y2 = hull[mid2].f(x);
        if(y1 <= y2) result = hull[mid2], lo = mid1 + 1;
        else result = hull[mid1], hi = mid2 - 1;
    }
    return result;
}
```
