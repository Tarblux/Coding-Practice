# Design Underground System

Problem: 1396
Official Difficulty: medium
Feels Like : medium
My Understanding: Fully Understand
Topic: design, hash table, string
Link: https://leetcode.com/problems/design-underground-system/description/
Completed On : April 24, 2024
Last Review: April 24, 2024
Days Since Review: 6

## Problem

---

An underground railway system is keeping track of customer travel times 
between different stations. They are using this data to calculate the 
average time it takes to travel from one station to another.

Implement the `UndergroundSystem` class:

- `void checkIn(int id, string stationName, int t)`
    - A customer with a card ID equal to `id`, checks in at the station `stationName` at time `t`.
    - A customer can only be checked into one place at a time.
- `void checkOut(int id, string stationName, int t)`
    - A customer with a card ID equal to `id`, checks out from the station `stationName` at time `t`.
- `double getAverageTime(string startStation, string endStation)`
    - Returns the average time it takes to travel from `startStation` to `endStation`.
    - The average time is computed from all the previous traveling times from `startStation` to `endStation` that happened **directly**, meaning a check in at `startStation` followed by a check out from `endStation`.
    - The time it takes to travel from `startStation` to `endStation` **may be different** from the time it takes to travel from `endStation` to `startStation`.
    - There will be at least one customer that has traveled from `startStation` to `endStation` before `getAverageTime` is called.

You may assume all calls to the `checkIn` and `checkOut` methods are consistent. If a customer checks in at time `t1` then checks out at time `t2`, then `t1 < t2`. All events happen in chronological order.

**Example 1:**

```
Input
["UndergroundSystem","checkIn","checkIn","checkIn","checkOut","checkOut","checkOut","getAverageTime","getAverageTime","checkIn","getAverageTime","checkOut","getAverageTime"]
[[],[45,"Leyton",3],[32,"Paradise",8],[27,"Leyton",10],[45,"Waterloo",15],[27,"Waterloo",20],[32,"Cambridge",22],["Paradise","Cambridge"],["Leyton","Waterloo"],[10,"Leyton",24],["Leyton","Waterloo"],[10,"Waterloo",38],["Leyton","Waterloo"]]

Output
[null,null,null,null,null,null,null,14.00000,11.00000,null,11.00000,null,12.00000]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(45, "Leyton", 3);
undergroundSystem.checkIn(32, "Paradise", 8);
undergroundSystem.checkIn(27, "Leyton", 10);
undergroundSystem.checkOut(45, "Waterloo", 15);  // Customer 45 "Leyton" -> "Waterloo" in 15-3 = 12
undergroundSystem.checkOut(27, "Waterloo", 20);  // Customer 27 "Leyton" -> "Waterloo" in 20-10 = 10
undergroundSystem.checkOut(32, "Cambridge", 22); // Customer 32 "Paradise" -> "Cambridge" in 22-8 = 14
undergroundSystem.getAverageTime("Paradise", "Cambridge"); // return 14.00000. One trip "Paradise" -> "Cambridge", (14) / 1 = 14
undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000. Two trips "Leyton" -> "Waterloo", (10 + 12) / 2 = 11
undergroundSystem.checkIn(10, "Leyton", 24);
undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 11.00000
undergroundSystem.checkOut(10, "Waterloo", 38);  // Customer 10 "Leyton" -> "Waterloo" in 38-24 = 14
undergroundSystem.getAverageTime("Leyton", "Waterloo");    // return 12.00000. Three trips "Leyton" -> "Waterloo", (10 + 12 + 14) / 3 = 12

```

**Example 2:**

```
Input
["UndergroundSystem","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime","checkIn","checkOut","getAverageTime"]
[[],[10,"Leyton",3],[10,"Paradise",8],["Leyton","Paradise"],[5,"Leyton",10],[5,"Paradise",16],["Leyton","Paradise"],[2,"Leyton",21],[2,"Paradise",30],["Leyton","Paradise"]]

Output
[null,null,null,5.00000,null,null,5.50000,null,null,6.66667]

Explanation
UndergroundSystem undergroundSystem = new UndergroundSystem();
undergroundSystem.checkIn(10, "Leyton", 3);
undergroundSystem.checkOut(10, "Paradise", 8); // Customer 10 "Leyton" -> "Paradise" in 8-3 = 5
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.00000, (5) / 1 = 5
undergroundSystem.checkIn(5, "Leyton", 10);
undergroundSystem.checkOut(5, "Paradise", 16); // Customer 5 "Leyton" -> "Paradise" in 16-10 = 6
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.50000, (5 + 6) / 2 = 5.5
undergroundSystem.checkIn(2, "Leyton", 21);
undergroundSystem.checkOut(2, "Paradise", 30); // Customer 2 "Leyton" -> "Paradise" in 30-21 = 9
undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 6.66667, (5 + 6 + 9) / 3 = 6.66667

```

**Constraints:**

- `1 <= id, t <= 106`
- `1 <= stationName.length, startStation.length, endStation.length <= 10`
- All strings consist of uppercase and lowercase English letters and digits.
- There will be at most `2 * 104` calls **in total** to `checkIn`, `checkOut`, and `getAverageTime`.
- Answers within `105` of the actual value will be accepted.

## My Solutions

---

```python
from collections import defaultdict
class UndergroundSystem:

    def __init__(self):

        self.customers = defaultdict(list)
        self.times = defaultdict(list)

    def checkIn(self, id: int, stationName: str, t: int) -> None:

        if self.customers[id]: return
        self.customers[id].append([stationName,t])
        
    def checkOut(self, id: int, stationName: str, t: int) -> None:

        if id not in self.customers : return

        start , time = self.customers[id][0]
        self.times[(start,stationName)].append(t - time)
        self.customers[id] = []
        
    def getAverageTime(self, startStation: str, endStation: str) -> float:

        all_times = self.times[(startStation,endStation)]

        average_time = sum(all_times)/len(all_times)

        return average_time
```

```python

```

## Optimal Solutions

---

The problem "Design Underground System" involves creating a system that can track the average travel time between different subway stations. This system should be able to handle check-ins and check-outs by customers and compute average times based on multiple trips between the same start and end stations.

### Requirements and Functionalities:

1. **Check-in(id, stationName, t)**: A customer with a unique id checks into a station at time `t`.
2. **Check-out(id, stationName, t)**: The customer with the same id checks out from a station at time `t`.
3. **getAverageTime(startStation, endStation)**: Returns the average time to travel between the start and end station.

### Approach to Solution:

To efficiently manage this system, you can use two primary data structures:

1. **Check-in Data**: A dictionary to store check-in data where the key is the user's ID and the value is a tuple containing the station name and check-in time.
2. **Travel Times Data**: A dictionary to maintain all trips between pairs of stations. The key would be a tuple (startStation, endStation) and the value would be a list or another structure to keep track of total travel time and count of trips.

### Implementation Details:

- For the check-in data, use a dictionary where keys are customer IDs.
- For the travel times data, use a dictionary where keys are tuples representing station pairs, and values are tuples holding the total travel time and the count of trips between those stations.

### Pseudo Code:

```python
class UndergroundSystem:
    def __init__(self):
        self.check_ins = {}  # Maps customer ID -> (stationName, time)
        self.travel_times = {}  # Maps (startStation, endStation) -> (totalTime, count)

    def checkIn(self, id, stationName, time):
        self.check_ins[id] = (stationName, time)

    def checkOut(self, id, stationName, time):
        startStation, startTime = self.check_ins.pop(id)  # Remove check-in data
        if (startStation, stationName) not in self.travel_times:
            self.travel_times[(startStation, stationName)] = (0, 0)
        total_time, count = self.travel_times[(startStation, stationName)]
        new_total_time = total_time + (time - startTime)
        new_count = count + 1
        self.travel_times[(startStation, stationName)] = (new_total_time, new_count)

    def getAverageTime(self, startStation, endStation):
        total_time, count = self.travel_times.get((startStation, endStation), (0, 1))
        return total_time / count

```

### Example Usage:

- **checkIn(1, "Leyton", 3)**: A user with ID 1 checks in at "Leyton" at time 3.
- **checkOut(1, "Waterloo", 15)**: The same user checks out at "Waterloo" at time 15.
- **getAverageTime("Leyton", "Waterloo")**: Returns the average time taken from "Leyton" to "Waterloo".

This approach ensures that operations are efficient:

- **Time Complexity**: Each method (`checkIn`, `checkOut`, `getAverageTime`) operates in O(1) time.
- **Space Complexity**: Space usage grows linearly with the number of users and distinct station pairs but is efficient in terms of operations.

This system design efficiently manages the check-in and check-out processes, calculating average times dynamically while ensuring quick responses to queries.

## Notes

---

 

## Related Videos

---

[https://www.youtube.com/watch?v=W5QOLqXskZM](https://www.youtube.com/watch?v=W5QOLqXskZM)