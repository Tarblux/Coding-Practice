# Simple Banking System

Problem: 1716
Official Difficulty: medium
My Understanding: Fully Understand
Feels Like : easy
Topic: Math, design
Link: https://leetcode.com/problems/simple-bank-system/submissions/1184418368/
Completed On : February 23, 2024
Last Review: February 23, 2024
Days Since Review: 3

## Problem

---

You have been tasked with writing a program for a popular bank that 
will automate all its incoming transactions (transfer, deposit, and 
withdraw). The bank has `n` accounts numbered from `1` to `n`. The initial balance of each account is stored in a **0-indexed** integer array `balance`, with the `(i + 1)th` account having an initial balance of `balance[i]`.

Execute all the **valid** transactions. A transaction is **valid** if:

- The given account number(s) are between `1` and `n`, and
- The amount of money withdrawn or transferred from is **less than or equal** to the balance of the account.

Implement the `Bank` class:

- `Bank(long[] balance)` Initializes the object with the **0-indexed** integer array `balance`.
- `boolean transfer(int account1, int account2, long money)` Transfers `money` dollars from the account numbered `account1` to the account numbered `account2`. Return `true` if the transaction was successful, `false` otherwise.
- `boolean deposit(int account, long money)` Deposit `money` dollars into the account numbered `account`. Return `true` if the transaction was successful, `false` otherwise.
- `boolean withdraw(int account, long money)` Withdraw `money` dollars from the account numbered `account`. Return `true` if the transaction was successful, `false` otherwise.

## My Solutions

---

```python
class Bank:

    def __init__(self, balance: List[int]):

        self.balance = balance.copy()
        
    def transfer(self, account1: int, account2: int, money: int) -> bool:

        if account1 - 1 <= len(self.balance) and account2 - 1 <= len(self.balance) :

            if self.balance[account1-1] < money : 

                return False

            else : 

                self.balance[account1-1] -= money 

                self.balance[account2-1] += money

                return True

        return False

    def deposit(self, account: int, money: int) -> bool:

        if account - 1 <= len(self.balance):

            self.balance[account-1] += money

            return True

        else : 

            return False

    def withdraw(self, account: int, money: int) -> bool:

        if account - 1 <= len(self.balance):

            if self.balance[account-1] >= money :

                self.balance[account-1] -= money

                return True

            else : 

                return False

            return False

# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
```

Sanya’s more scalable and elegant solution

```python
class Bank:

    def __init__(self, balance: List[int]):
        self.accounts = [i + 1 for i in range(0, len(balance))]
        self.balances = balance 

    def valid_account(self, account: int):    
        if account > 0 and account <= len(self.accounts):
            return True
        return False

    def sufficient_balance(self, account: int, money: int):
        if self.balances[account - 1] - money >= 0:
            return True
        return False

    def transfer(self, account1: int, account2: int, money: int) -> bool:
        if not self.valid_account(account1) or not self.valid_account(account2):
            return False
        if not self.sufficient_balance(account1, money):
            return False
        self.balances[account1 - 1] -= money
        self.balances[account2 - 1] += money
        return True

    def deposit(self, account: int, money: int) -> bool:
        if not self.valid_account(account):
            return False
        self.balances[account - 1] += money
        return True
        

    def withdraw(self, account: int, money: int) -> bool:
        if not self.valid_account(account):
            return False
        if not self.sufficient_balance(account, money):
            return False
        self.balances[account - 1] -= money
        return True
        
        
        

# Your Bank object will be instantiated and called as such:
# obj = Bank(balance)
# param_1 = obj.transfer(account1,account2,money)
# param_2 = obj.deposit(account,money)
# param_3 = obj.withdraw(account,money)
```

## Optimal Solutions

---

## Notes

---

 

## Related Videos

---

[https://www.notion.so](https://www.notion.so)