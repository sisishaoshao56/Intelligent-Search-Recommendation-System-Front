import java.util.ArrayList;
import java.util.Date;


class Transaction{
    private Date data;
    private char type;
    private double balance;
    private double amount;

    private String description;
    Transaction(){};
    Transaction(char type,double amount,double balance,String description){
        this.type=type;
        this.amount=amount;
        this.balance=balance;
        this.description=description;
    }

}
class Account{
    private int id=0;
    private String name;
    private double balance=0;
    private double annualInterestRate=0;
    private Date dataCreated ;
    private ArrayList<Transaction> transactions;
    Account(){};
    Account(int id,double balance){
        this.id=id;
        this.balance=balance;
    }
    Account(String name,int id,ArrayList<Transaction> transactions){
        this.name=name;
        this.balance=balance;
        this.transactions=transactions;
    }
    public void setName(String name){
        this.name=name;
    }
    public String getName(){
        return name;
    }
    public void setId(int id){
        this.id=id;
    }
    public int getId(){
        return id;
    }
    public void setAnnualInterestRate(double annualInterestRate){
        this.annualInterestRate=annualInterestRate;
    }
    public double getAnnualInterestRate(){
        return annualInterestRate;
    }
    public Date getDataCreated(){
        return dataCreated;
    }
    public double getMonthlyInterest(){
        return balance*getMonthlyInterestRate();
    }
    public double getMonthlyInterestRate(){
        return getAnnualInterestRate()/12;
    }
    public void withDraw(double amount){
        balance-=amount;
        transactions.add(new Transaction('W',amount,balance,"withDraw"));
    }
    public void deposit(double amount){
        balance+=amount;
        transactions.add(new Transaction('D',amount,balance,"deposit"));
    }
}
public class _3 {
    Account acc = new Account(1122, 20000);
    acc.setAnnualInterestRate(1.5);

}
