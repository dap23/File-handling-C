#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct buyer {
    char rno[20];
    char nama[20],alamat[50];
    
}buyer;

void create(){
    int i,n;
    struct buyer b;
    FILE *fp;

    fp = fopen("buyer.txt", "wb");

    printf("\nMasukan jumlah data yang akan diinput: ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("\nMasukan Nama: ");
        scanf("%s", b.nama);
        printf("Masukan No Hp: ");
        scanf("%s", b.rno);
        printf("Masukan Alamat: ");
        scanf("%s", b.alamat);

        fwrite(&b,sizeof(buyer),1,fp);
    }
    fclose(fp);

}
void display(){
    int i,n;
    struct buyer b;
    FILE *fp;
    fp = fopen("buyer.txt", "rb");
    while (fread(&b,sizeof(buyer),1,fp))
    {
        printf("\n%s", b.nama);
        printf("\n%s", b.rno);
        printf("\n%s\n", b.alamat);
    }
    
    fclose(fp);
}
void update(){
    char n[20];
    int found=0;
    struct buyer b;
    FILE *fp, *fp1;
    fp = fopen("buyer.txt", "rb");
    fp1 = fopen("temp.txt", "wb");

    printf("Masukan Nama untuk di Ubah: ");
    scanf("%s", n);
    while (fread(&b,sizeof(buyer),1,fp))
    {
        if (strcmp(b.nama, n) == 0){
            found = 1;
            printf("Masukan No Hp Baru: ");
            scanf("%s", b.rno);
            printf("Masukan Alamat Baru: ");
            scanf("%s", b.alamat);

        }
        fwrite(&b, sizeof(buyer),1,fp1);
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("buyer.txt", "w");

        while(fread(&b, sizeof(buyer),1,fp1)){
            fwrite(&b, sizeof(buyer),1,fp);

        }

        fclose(fp);
        fclose(fp1);    

    } else {
        printf("\nData tidak ditemukan\n");

    }
    
}


void cari(){
    char n[20];
    int found=0;
    struct buyer b;
    FILE *fp;
    fp = fopen("buyer.txt", "rb");
    printf("Masukan Nama untuk di Cari: ");
    scanf("%s", n);
    while (fread(&b,sizeof(buyer),1,fp))
    {
        if (strcmp(b.nama, n) == 0){
            found = 1;
            printf("\n%s", b.nama);
            printf("\n%s", b.rno);
            printf("\n%s\n", b.alamat);

        }
        
    }
    if(!found){
        printf("\nData tidak ditemukan\n");
    }
    
    fclose(fp);
}


void destroy(){
    char n[20];
    int found=0;
    struct buyer b;
    FILE *fp, *fp1;
    fp = fopen("buyer.txt", "rb");
    fp1 = fopen("temp.txt", "wb");

    printf("Masukan Nama untuk di Hapus: ");
    scanf("%s", n);
    while (fread(&b,sizeof(buyer),1,fp))
    {
        if (strcmp(b.nama, n) == 0){
            found = 1;
        } else {
            fwrite(&b, sizeof(buyer),1,fp1);
        }

    }
    fclose(fp);
    fclose(fp1);
    if(found){
        fp1 = fopen("temp.txt", "r");
        fp = fopen("buyer.txt", "w");

        while(fread(&b, sizeof(buyer),1,fp1)){
            fwrite(&b, sizeof(buyer),1,fp);

        }

        fclose(fp);
        fclose(fp1);    

    } else {
        printf("\nData tidak ditemukan\n");

    }

}

int main(){
    int ch;
    do
    {
        printf("\nProgram Sasuke Express");
        printf("\n");
        printf("\n1. Menambah Data");
        printf("\n2. Menampikan Data");
        printf("\n3. Mengubah Data");
        printf("\n4. Mencari Data");
        printf("\n5. Menghapus Data");
        printf("\n0. Keluar");

        printf("\nPilihan : ");
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
            update();
        break;

        case 4:
            cari();
        break;

        case 5:
            destroy();
        break;
        
                }
    } while (ch!=0);
    
    return 0;
}
