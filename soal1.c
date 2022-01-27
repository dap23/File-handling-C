#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
typedef struct goods
{
char goods_code[6];
char goods_descrip[20];
float price;
}goodtype;

goodtype goods[8];
strcpy(goods[0].goods_descrip, "Croissant Almond");
strcpy(goods[0].goods_code, "00310");
goods[0].price = 25.000;

strcpy(goods[1].goods_descrip, "Beef Croissant");
strcpy(goods[1].goods_code, "00311");
goods[1].price = 27.500;

strcpy(goods[2].goods_descrip, "Croffle");
strcpy(goods[2].goods_code, "00322");
goods[2].price = 27.000;

strcpy(goods[3].goods_descrip, "Apple Puff");
strcpy(goods[3].goods_code, "00323");
goods[3].price = 22.000;

strcpy(goods[4].goods_descrip, "Pie Apple");
strcpy(goods[4].goods_code, "00510");
goods[4].price = 25.000;

strcpy(goods[5].goods_descrip, "Espresso");
strcpy(goods[5].goods_code, "00511");
goods[5].price = 18.000;

strcpy(goods[6].goods_descrip, "Cafe Latte");
strcpy(goods[6].goods_code, "00512");
goods[6].price = 25.000;

strcpy(goods[7].goods_descrip, "Cappuccino");
strcpy(goods[7].goods_code, "00513");
goods[7].price = 25.000;

char tempCode[6];
typedef struct receipt
{
char receiptNM[20], receiptCD[6];
float receiptPC;
}receipttype;
receipttype receipt[8];
char stop[2] = {"q"};
float ttlcost = 0;
unsigned int i;
unsigned int count = 0;
printf("Food\n");
printf("\nCroissant Almond (00310)");
printf("\nBeef Croissant (00311)");
printf("\nCroffle (00322)");
printf("\nApple Puff (00323)");
printf("\nPie Apple (00510)\n");
printf("\n");
printf("Drink\n");
printf("Espresso (00511)\n");
printf("Cafe Latte (00512)\n");
printf("Cappuccino (00513)\n");


while ( strcmp(tempCode, stop) ){
    printf("Please enter the item code. Type q to finish: ");
    scanf("%s", tempCode);
    for (i = 0; i <= 12; ++i){
        if (strcmp(tempCode, goods[i].goods_code) == 0){
            strcpy(receipt[count].receiptNM, goods[i].goods_descrip);
            strcpy(receipt[count].receiptCD, goods[i].goods_code);
            receipt[count].receiptPC = goods[i].price;
            ttlcost += goods[i].price;
            count++;
        }

    }

}
printf("_____________________________________\n\n");
printf("      THANK YOU FOR VISITING US!     \n");
printf("_____________________________________\n");
printf("         Here is your receipt:       \n\n");
printf("%10s%20s%10s", "Item", "Code", "Price\n");
for (int j= 0; j < count; ++j){
printf("%10s%20s%10.3f\n", receipt[j].receiptNM, receipt[j].receiptCD, receipt[j].receiptPC);
}
printf("\n_____________________________________\n");
printf("          TOTAL COST:%.3f            \n", ttlcost);
}