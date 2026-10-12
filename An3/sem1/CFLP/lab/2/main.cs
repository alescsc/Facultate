using System;
using System.Collections.Generic;

public enum AccountType
{
    Person,
    Company
}

public class Account
{
    public string AccountHolder { get; private set; }
    public AccountType Type { get; private set; }
    public string Iban { get; private set; }
    public decimal Amount { get; private set; }

    public Account(string accountHolder, AccountType type, string iban, decimal initialAmount)
    {
        AccountHolder = accountHolder;
        Type = type;
        Iban = iban;
        Amount = initialAmount;
    }

    public void Deposit(decimal amount)
    {
        if (amount > 0)
        {
            Amount += amount;
        }
    }

    public void Withdraw(decimal amount)
    {
        if (amount > 0 && Amount >= amount)
        {
            Amount -= amount;
        }
        else
        {
            Console.WriteLine($"Fonduri insuficiente in contul {Iban}.");
        }
    }

    public override string ToString()
    {
        return $"Titular: {AccountHolder} | Tip: {Type} | IBAN: {Iban} | Sold: {Amount} RON";
    }
}

public class Bank
{
    public string Name { get; private set; }
    public string Swift { get; private set; }
    public List<Account> Accounts { get; private set; }

    public Bank(string name, string swift)
    {
        Name = name;
        Swift = swift;
        Accounts = new List<Account>();
    }

    private Account GetAccount(string iban)
    {
        foreach (Account acc in Accounts)
        {
            if (acc.Iban == iban)
            {
                return acc;
            }
        }
        return null; 
    }

    public void OpenAccount(Account account)
    {
        Accounts.Add(account);
        Console.WriteLine($"Cont deschis cu succes pentru {account.AccountHolder}.");
    }

    public void ShowAccountDetails(string iban)
    {
        Account acc = GetAccount(iban);
        if (acc != null)
        {
            Console.WriteLine(acc.ToString());
        }
        else
        {
            Console.WriteLine("Contul nu a fost gasit.");
        }
    }

    public void DepositToAccount(string iban, decimal amount)
    {
        Account acc = GetAccount(iban);
        if (acc != null)
        {
            acc.Deposit(amount);
            Console.WriteLine($"S-au depus {amount} in contul {iban}.");
        }
    }

    public void WithdrawFromAccount(string iban, decimal amount)
    {
        Account acc = GetAccount(iban);
        if (acc != null)
        {
            acc.Withdraw(amount);
        }
    }

    public void Transfer(string fromIban, string toIban, decimal amount)
    {
        Account fromAcc = GetAccount(fromIban);
        Account toAcc = GetAccount(toIban);

        if (fromAcc != null && toAcc != null)
        {
            if (fromAcc.Amount >= amount)
            {
                fromAcc.Withdraw(amount);
                toAcc.Deposit(amount);
                Console.WriteLine($"Transfer reusit: {amount} de la {fromIban} la {toIban}.");
            }
            else
            {
                Console.WriteLine("Fonduri insuficiente pentru transfer.");
            }
        }
        else
        {
            Console.WriteLine("Unul sau ambele conturi nu au fost gasite.");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        Bank myBank = new Bank("Banca Centrala", "BNCARO");

        Account cont1 = new Account("Ion Popescu", AccountType.Person, "RO111", 1000);
        Account cont2 = new Account("Firma IT SRL", AccountType.Company, "RO222", 5000);

        myBank.OpenAccount(cont1);
        myBank.OpenAccount(cont2);

        Console.WriteLine("\n--- Detalii Initiale ---");
        myBank.ShowAccountDetails("RO111");
        myBank.ShowAccountDetails("RO222");

        Console.WriteLine("\n--- Operatiuni ---");
        myBank.DepositToAccount("RO111", 500); 
        myBank.Transfer("RO222", "RO111", 1000); 

        Console.WriteLine("\n--- Detalii Finale ---");
        myBank.ShowAccountDetails("RO111");
        myBank.ShowAccountDetails("RO222");
    }
}