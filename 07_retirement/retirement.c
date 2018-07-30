#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double calculate_balance(int startAge, double initial, retire_info info) {
  double balance = initial;
  int age = startAge;
  for (int i=1; i<=info.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", age / 12, age % 12, balance);
    age++;
    balance += info.contribution + balance * info.rate_of_return;
  }
  
  return balance;
}

void retirement(int startAge,   //in months
		double initial, //initial savings in dollars
		retire_info working, //info about working
		retire_info retired) //info about being retired
{
  double balance;
  
  balance = calculate_balance(startAge, initial, working);
  balance = calculate_balance(startAge+working.months, balance, retired);
}

int main(void) {
  retire_info working;
  retire_info retired;

  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  int startAge = 327;
  double initial = 21345;
  retirement(startAge, initial, working, retired);

  return EXIT_SUCCESS;
}
