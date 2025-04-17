# Detailed Binary Search (Python Edition)

**Translator & Adaptor: You**

**Original Author: labuladong**

---

## 📖 Introduction

Binary search is deceptively simple yet notoriously tricky. As Donald Knuth said:
> "Although the basic idea of binary search is comparatively straightforward, the details can be surprisingly tricky."

The real challenge isn't overflow or syntax, but **understanding the boundaries and loop conditions**. Should the loop be `while left <= right` or `while left < right`? Should `mid` be included or excluded next? This guide walks through it all.

---

## 🔧 Binary Search Framework (Python)

```python
# Template
while left <= right:
    mid = left + (right - left) // 2
    if nums[mid] == target:
        return mid
    elif nums[mid] < target:
        left = mid + 1
    elif nums[mid] > target:
        right = mid - 1
```

> Tip: Use `left + (right - left) // 2` to avoid integer overflow (not critical in Python, but good habit).

---

## 1️⃣ Search for a Number (Exact Match)

### Problem:
Find a target in a sorted array. Return the index if found; otherwise, return -1.

```python
def binary_search(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1

    return -1
```

**Why `<=`?** Because `right` is `len(nums) - 1`. We're using a closed interval `[left, right]`.

---

## 2️⃣ Search for the Left Boundary (First Occurrence)

### Problem:
Find the **first occurrence** of `target` in a sorted array.

```python
def left_bound(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        elif nums[mid] == target:
            right = mid - 1

    if left >= len(nums) or nums[left] != target:
        return -1
    return left
```

**Key difference:**
- When `nums[mid] == target`, we **do not return immediately**.
- Instead, shrink the `right` boundary to continue searching left.

---

## 3️⃣ Search for the Right Boundary (Last Occurrence)

### Problem:
Find the **last occurrence** of `target` in a sorted array.

```python
def right_bound(nums: List[int], target: int) -> int:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target:
            right = mid - 1
        elif nums[mid] == target:
            left = mid + 1

    if right < 0 or nums[right] != target:
        return -1
    return right
```

**Key difference:**
- When `nums[mid] == target`, increase `left` to `mid + 1` to search further right.
- After the loop, `right` points to the last valid occurrence of `target`.

---

## 🔁 Summary: Three Binary Search Variants

| Purpose               | Match Case            | Move Left       | Move Right       | Final Return Check              |
|----------------------|------------------------|------------------|-------------------|----------------------------------|
| Exact Match          | `return mid`          | `right = mid - 1`| `left = mid + 1`  | `return -1 if not found`        |
| Left Boundary        | `right = mid - 1`     | `right = mid - 1`| `left = mid + 1`  | `left >= n or nums[left] != t`  |
| Right Boundary       | `left = mid + 1`      | `right = mid - 1`| `left = mid + 1`  | `right < 0 or nums[right] != t` |

---

## 🧠 Tips for Mastering Binary Search

1. Always define your **search interval** clearly: is it `[left, right]` or `[left, right)`?
2. Use `left + (right - left) // 2` to prevent overflow.
3. For boundary problems, **never return immediately** when you find `target` — keep shrinking the search space.
4. Add out-of-bound checks when returning `left` or `right`.
5. Practice makes perfect — the more you implement all three types, the easier it becomes.

---

If you understand and master these three binary search patterns, you can write them with your eyes closed 😎