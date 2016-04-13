# include<stdio.h>

float weight[20], profit[20], x[20], capacity;
int num, n, i, j;
float ratio[20], temp;

void knapsack() {
   float tp = 0;
   int i, u;
   u = capacity;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (weight[i] > u)
         break;
      else {
         x[i] = 1.0;
         tp = tp + profit[i];
         u = u - weight[i];
      }
   }

   if (i < n)
      x[i] = u / weight[i];

   tp = tp + (x[i] * profit[i]);

   printf("\nThe result is:- ");
   for (i = 0; i < n; i++)
      printf("%f\t", x[i]);

   printf("\nMaximum profit is:- %f", tp);

}

void init(){
  printf("\nEnter the number of items you will be using: ");
  scanf("%d", &num);
  n = num;

  printf("\nEnter the weights and profits of each item ex: (5 6): ");
  for (i = 0; i < num; i++) {
     scanf("%f %f", &weight[i], &profit[i]);
  }

  printf("\nEnter the capacity of the knapsack:- ");
  scanf("%f", &capacity);

  for (i = 0; i < num; i++) {
     ratio[i] = profit[i] / weight[i];
  }

  for (i = 0; i < num; i++) {
     for (j = i + 1; j < num; j++) {
        if (ratio[i] < ratio[j]) {
           temp = ratio[j];
           ratio[j] = ratio[i];
           ratio[i] = temp;

           temp = weight[j];
           weight[j] = weight[i];
           weight[i] = temp;

           temp = profit[j];
           profit[j] = profit[i];
           profit[i] = temp;
        }
     }
  }

}
