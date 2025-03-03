# Design Twitter

Problem: 355
Official Difficulty: medium
Feels Like : hard
My Understanding: I Have No Idea
Topic: Heap(Priority Queue), design, hash table, linked list
Link: https://leetcode.com/problems/design-twitter/description/
Completed On : November 16, 2024
Last Review: November 16, 2024
Days Since Review: 106
Neetcode: Yes

## Problem

---

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the `10` most recent tweets in the user's news feed.

Implement the `Twitter` class:

- `Twitter()` Initializes your twitter object.
- `void postTweet(int userId, int tweetId)` Composes a new tweet with ID `tweetId` by the user `userId`. Each call to this function will be made with a unique `tweetId`.
- `List<Integer> getNewsFeed(int userId)` Retrieves the `10` most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be **ordered from most recent to least recent**.
- `void follow(int followerId, int followeeId)` The user with ID `followerId` started following the user with ID `followeeId`.
- `void unfollow(int followerId, int followeeId)` The user with ID `followerId` started unfollowing the user with ID `followeeId`.

**Example 1:**

```
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
```

**Constraints:**

- `1 <= userId, followerId, followeeId <= 500`
- `0 <= tweetId <= 104`
- All the tweets have **unique** IDs.
- At most `3 * 104` calls will be made to `postTweet`, `getNewsFeed`, `follow`, and `unfollow`.

## My Solutions

---

```python

```

```python

```

## Optimal Solutions

---

To solve **LeetCode Problem 355: Design Twitter**, we need to design a simplified version of Twitter where users can post tweets, follow/unfollow other users, and retrieve the 10 most recent tweets in a user's news feed. The challenge is to implement these functionalities efficiently.

---

### **Problem Requirements**

Implement the following methods:

1. **`postTweet(userId, tweetId)`**: Compose a new tweet.
2. **`getNewsFeed(userId)`**: Retrieve the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user follows or by the user themselves. Tweets must be ordered from most recent to least recent.
3. **`follow(followerId, followeeId)`**: Follower follows a followee.
4. **`unfollow(followerId, followeeId)`**: Follower unfollows a followee.

---

### **Optimal Algorithm and Data Structures**

To meet the requirements efficiently, we need to:

- **Store tweets with timestamps** to order them by recency.
- **Maintain a mapping of users to the users they follow**.
- **Efficiently retrieve the most recent tweets** from a user's followees.

We can achieve this by:

1. **Using a global timestamp** to track the order of tweets.
2. **Storing tweets per user** with their timestamps.
3. **Using a min-heap** to retrieve the top 10 most recent tweets efficiently.

---

### **Algorithm Implementation**

### **Data Structures**

- **`self.timestamp`**: A global counter incremented every time a tweet is posted.
- **`self.tweets`**: A dictionary mapping `userId` to a list of tuples `(timestamp, tweetId)`.
- **`self.followees`**: A dictionary mapping `userId` to a set of `followeeIds`.

### **Methods**

1. **`postTweet(userId, tweetId)`**
    - Append the tweet with the current timestamp to the user's tweet list.
2. **`getNewsFeed(userId)`**
    - Initialize a min-heap.
    - Add the most recent tweet from the user and each followee to the heap.
    - Use a pointer for each user's tweet list to track the next tweet.
    - Pop tweets from the heap up to 10 times to get the most recent tweets.
3. **`follow(followerId, followeeId)`**
    - Add `followeeId` to `followerId`'s followee set.
4. **`unfollow(followerId, followeeId)`**
    - Remove `followeeId` from `followerId`'s followee set if it exists.

---

### **Code Implementation**

```python
import heapq
from collections import defaultdict

class Twitter:

    def __init__(self):
        self.timestamp = 0  # Global timestamp
        self.tweets = defaultdict(list)  # userId -> list of (timestamp, tweetId)
        self.followees = defaultdict(set)  # userId -> set of followeeIds

    def postTweet(self, userId: int, tweetId: int) -> None:
        # Add tweet to the user's list with current timestamp
        self.timestamp += 1
        self.tweets[userId].append((self.timestamp, tweetId))

    def getNewsFeed(self, userId: int) -> List[int]:
        heap = []
        # Get the user's own tweets
        users = self.followees[userId] | {userId}
        for uid in users:
            tweets = self.tweets[uid]
            if tweets:
                idx = len(tweets) - 1
                time, tweetId = tweets[idx]
                # Push (time, tweetId, uid, idx) to the heap
                heapq.heappush(heap, (-time, tweetId, uid, idx - 1))

        result = []
        while heap and len(result) < 10:
            time, tweetId, uid, idx = heapq.heappop(heap)
            result.append(tweetId)
            if idx >= 0:
                time, tweetId = self.tweets[uid][idx]
                heapq.heappush(heap, (-time, tweetId, uid, idx - 1))

        return result

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.followees[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followees[followerId].discard(followeeId)

```

---

### **Explanation**

- **Posting a Tweet (`postTweet`):**
    - Increment the global `timestamp`.
    - Append `(timestamp, tweetId)` to the user's tweet list.
- **Getting the News Feed (`getNewsFeed`):**
    - **Collect Tweets:**
        - Combine the user's own tweets and those of their followees.
        - Start from the most recent tweet for each user.
    - **Use a Max Heap:**
        - Push the most recent tweet from each user into a max heap (negate the timestamp to simulate a max heap using Python's min-heap).
        - Each heap element is a tuple `(-time, tweetId, userId, next_idx)` where `next_idx` points to the next tweet from that user.
    - **Build the News Feed:**
        - Pop the tweet with the highest timestamp (most recent) from the heap.
        - Add the `tweetId` to the result list.
        - If there are more tweets from the same user, push the next tweet into the heap.
        - Continue until we have 10 tweets or the heap is empty.
- **Following a User (`follow`):**
    - Add `followeeId` to the set of users that `followerId` is following.
- **Unfollowing a User (`unfollow`):**
    - Remove `followeeId` from `followerId`'s followee set.

---

### **Time and Space Complexity Analysis**

### **Time Complexity**

- **`postTweet`**: O(1)
    - Appending to a list is constant time.
- **`getNewsFeed`**: O(N log k), where:
    - **N**: Total number of users being followed (including the user themselves).
    - **k**: Number of tweets per user (bounded by the total number of tweets).
    - Since we limit the news feed to 10 tweets, the heap operations are bounded.
- **`follow`**: O(1)
    - Adding to a set is constant time.
- **`unfollow`**: O(1)
    - Removing from a set is constant time.

### **Space Complexity**

- **Overall**: O(N * k), where:
    - **N**: Number of users.
    - **k**: Number of tweets per user.
- **Per User**:
    - **Tweets Storage**: O(k)
    - **Followees Storage**: O(f), where **f** is the number of followees per user.

---

### **Optimizations and Considerations**

- **Limiting Tweet Storage:**
    - To optimize space, we can limit the number of tweets stored per user (e.g., only keep the most recent 10 tweets).
    - However, this would prevent users from retrieving older tweets.
- **Handling Large Numbers of Followees:**
    - If a user follows a large number of users, `getNewsFeed` could become slow.
    - To mitigate this, we can limit the number of followees or optimize the data structures further.
- **Thread Safety:**
    - In a multi-threaded environment, ensure thread safety by using locks or concurrent data structures.
- **Scalability:**
    - For a production system, consider distributed data storage and caching mechanisms.

---

### **Example Usage**

```python
# Initialize Twitter
twitter = Twitter()

# User 1 posts a new tweet (id = 5)
twitter.postTweet(1, 5)

# User 1's news feed should return a list with tweet id 5
print(twitter.getNewsFeed(1))  # Output: [5]

# User 1 follows user 2
twitter.follow(1, 2)

# User 2 posts a new tweet (id = 6)
twitter.postTweet(2, 6)

# User 1's news feed should return a list with tweet ids [6, 5]
print(twitter.getNewsFeed(1))  # Output: [6, 5]

# User 1 unfollows user 2
twitter.unfollow(1, 2)

# User 1's news feed should return a list with tweet id 5
print(twitter.getNewsFeed(1))  # Output: [5]

```

---

### **Summary**

- **Data Structures Used:**
    - **Dictionary of Tweets:** Maps each user to their list of tweets with timestamps.
    - **Dictionary of Followees:** Maps each user to the set of users they follow.
    - **Heap:** Used in `getNewsFeed` to efficiently retrieve the most recent tweets.
- **Performance:**
    - Efficient posting and following/unfollowing operations with constant time complexity.
    - Efficient retrieval of the news feed with acceptable time complexity given the constraints.
- **Scalability:**
    - The solution can be scaled by optimizing storage and considering distributed systems for real-world applications.

---

### **Conclusion**

By using appropriate data structures and algorithms, we can efficiently implement the core functionalities of a simplified Twitter. The provided solution ensures optimal time and space complexities for each operation, making it suitable for handling a large number of users and tweets within the constraints of the problem.

## Notes

---

 

## Related Videos

---

[https://youtu.be/s8p8ukTyA2I](https://youtu.be/s8p8ukTyA2I)