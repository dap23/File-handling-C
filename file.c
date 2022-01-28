#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct file
{
    char nama[20], alamat[60], contact[20], waktu[20];
    float money;
}bank;

void create(){
    int ph;
    struct file f;
    FILE *fp;
    fp = fopen("data.txt", "wb");
    printf("Date(dd/mm/yyyy): ");
    scanf("%s", f.waktu);
    printf("Name: ");
    scanf("%s", f.nama);
    printf("Address: ");
    scanf("%s", f.alamat);
    printf("Phone number: ");
    scanf("%s", f.contact);
    do {
        printf("\nEnter your amount for deposit: ");
        scanf("%f", &f.money);
        if(f.money < 100000) {
            printf("Value must be greater than Rp100.000");
        } else if (f.money > 5000000) {
            printf("Value must be lower than Rp5000.000");
        } else{
            printf("\n0. Done: ");
            scanf("%d", &ph);
        }
        
    } while(ph!=0);
    fwrite(&f, sizeof(bank),1,fp);
    fclose(fp);


}
void display(){
    struct file f;
    FILE *fp;
    fp = fopen("data.txt", "rb");
    while (fread(&f, sizeof(bank),1,fp))
    {
        printf("%s %s %s %s %.2f\n", f.waktu, f.nama, f.alamat, f.contact, f.money);
    }
    
    fclose(fp);
}
void wd(){
    char n[20];
    float m,t;
    int found=0;
    struct file f;
    FILE *fp, *fp1;

    fp = fopen("data.txt", "rb");
    fp1 = fopen("temp.txt", "wb");

    printf("Enter Name Account: ");
    scanf("%s", n);
    while(fread(&f,sizeof(bank),1,fp))
    {
        if(strcmp(f.nama, n) == 0){
            found = 1;
            printf("Enter amount for withdraw: ");
            scanf("%f", &m);
            if(m < 100000){
                printf("Value must be greater than Rp100.000");
            } else if (m > 5000000){
                printf("Value must be lower than Rp5000.000");
            } else {
                t = f.money - m;
                printf("\nBalance: %.2f\n", t);
                f.money = t;
            }             
        }
        fwrite(&f, sizeof(bank),1,fp1);
         
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("data.txt", "w");
        
         while(fread(&f, sizeof(bank),1,fp1)){
            fwrite(&f, sizeof(bank),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    } else {
        printf("\nWrong Credential\n");
    }
    
}
void depo(){
    char n[20];
    float m,t;
    int found=0;
    struct file f;
    FILE *fp, *fp1;

    fp = fopen("data.txt", "rb");
    fp1 = fopen("temp.txt", "wb");

    printf("Enter Name Account: ");
    scanf("%s", n);
    while(fread(&f,sizeof(bank),1,fp))
    {
        if(strcmp(f.nama, n) == 0){
            found = 1;
            printf("Enter amount for withdraw: ");
            scanf("%f", &m);
            if(m < 100000){
                printf("Value must be greater than Rp100.000");
            } else if (m > 5000000){
                printf("Value must be lower than Rp5000.000");
            } else {
                t = f.money + m;
                printf("\nBalance: %.2f\n", t);
                f.money = t;
            }             
        }
        fwrite(&f, sizeof(bank),1,fp1);
         
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("data.txt", "w");
        
         while(fread(&f, sizeof(bank),1,fp1)){
            fwrite(&f, sizeof(bank),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    } else {
        printf("\nWrong Credential\n");
    }
}
void destroy(){
    char n[20];
    int found=0;
    struct file f;
    FILE *fp, *fp1;
    fp = fopen("data.txt", "rb");
    fp1 = fopen("temp.txt", "wb");

    printf("Enter Name Account: ");
    scanf("%s", n);
    while(fread(&f,sizeof(bank),1,fp)){
        if(strcmp(f.nama, n) == 0){
            found = 1;
        } else {
            fwrite(&f,sizeof(bank),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("data.txt", "w");

        while(fread(&f,sizeof(bank),1,fp1)){
            fwrite(&f,sizeof(bank),1,fp);
        }
        fclose(fp);
        fclose(fp1);
    } else {
        printf("\nWrong Credential\n");
    }
}

void add(){
    int ph;
    struct file f;
    FILE *fp;
    fp = fopen("data.txt", "ab");
    printf("Date(dd/mm/yyyy): ");
    scanf("%s", f.waktu);
    printf("Name: ");
    scanf("%s", f.nama);
    printf("Address: ");
    scanf("%s", f.alamat);
    printf("Phone number: ");
    scanf("%s", f.contact);
    do {
        printf("\nEnter your amount for deposit: ");
        scanf("%f", &f.money);
        if(f.money < 100000) {
            printf("Value must be greater than Rp100.000");
        } else if (f.money > 5000000) {
            printf("Value must be lower than Rp5000.000");
        } else{
            printf("\n0. Done: ");
            scanf("%d", &ph);
        }
        
    } while(ph!=0);
    fwrite(&f, sizeof(bank),1,fp);
    fclose(fp);

}


int main(){
    int ch;
    do
    {
        printf("-----------------------------------------------------");
        printf("\n1. Create Account");
        printf("\n2. Show Account");
        printf("\n3. Withdraw");
        printf("\n4. Deposit");
        printf("\n5. Delete Account");
        printf("\n6. Add Account");
        printf("\n0. Exit");
        printf("\n-----------------------------------------------------");
        printf("\nEnter: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            create();
            break;
        
        case 2:
            display();
            break;
        case 3:
            wd();
            break;
        case 4:
            depo();
            break;
        case 5:
            destroy();
            break;
        case 6:
            add();
            break;
        }

    } while (ch!=0);
    
}