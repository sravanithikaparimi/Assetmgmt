# include <stdio.h>
# include <string.h>
# include <stdlib.h>
int assetcount[500];
char status[500][50];
int count = 0;
void addAsset()
{
    int id;
    char stat[50];
    printf("enter asset ID:\n");
    scanf("%d", &id);
    printf("enter the status(inUse, maintenance,available):\n");
    scanf("%s", stat);
    assetcount[count] = id;
    strcpy(status[count],stat );
    count++;
    printf("❤️asset added successfully!❤️\n");
}
void displayAsset()
{
    if (count == 0)
    {
        printf("No Assets Found😔\n");
    }
    else
    {
        printf("=====Asset list=====");
        printf("\n=================\n");
        printf("%-10s %-15s\n", "Asset ID", "Asset status");
        printf("====================\n");
        for (int i = 0; i < count; i++)
        {
            printf("%-10d %-15s\n", assetcount[i], status[i]);
        }
        
    }
}
void searchAsset()
{
    int ID;
    int found = 0;
    printf("enter the assetID:\n");
    scanf("%d", &ID);
    for (int i = 0; i < count; i++)
    {
        if (assetcount[i] == ID)
        {
            found = 1;
            printf("asset found\n");
            break;
        }
    }    
        if (found == 0)
        {
            printf("asset not found\n");
        }
}
void updateAssetstatus()
{
    int id;
    char stat[50];
    int found = 0;
    printf("enter the asset id:\n");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (assetcount[i] == id)
        {
            found = 1;
            printf("current status : %s\n", status[i]);
            printf("enter the new status:\n");
            scanf("%s", stat);
            strcpy(status[i],stat);
            printf("❤️update successful❤️\n");
            break;
        }
    }
        if (found == 0)
        {
            printf("asset not f😔und\n");
        }
}
void deleteAsset()
{
    int id;
    int found = 0;
    printf("enter the asset to delete:\n");
    scanf("%d", &id);
    for (int i = 0; i < count; i++)
    {
        if (assetcount[i] == id)
        {
            found = 1;
            for (int j = i; j < count-1; j++)
            {
                assetcount[j] = assetcount[j+1];
                strcpy(status[j],status[j + 1]);
            }
            count--;
            printf("❤️successfully deleted asset❤️\n");
            break;
        }
        if(found == 0)
        {
            printf("asset not f😔und\n");
        }
    }
}
int menu()
{
    int open;
    printf("=========================\n");
    printf("IT ASSET MANAGEMENT\n");
    printf("=========================\n");
    printf("1.Add Assets\n");
    printf("2.Dispaly Assets\n");
    printf("3.Search Asset\n");
    printf("4.Update Asset Status\n");
    printf("5.Delete Asset\n");
    printf("6.Exit\n");
    printf("Enter Your Choice(1,2,3..): ");
    scanf("%d", &open);
    switch (open)
    {
    case 1:
        addAsset();
        break;
    case 2:
        displayAsset();
        break;
    case 3:
        searchAsset();
        break;
    case 4:
        updateAssetstatus();
        break;
    case 5:
        deleteAsset();
        break;
    case 6:
        exit(0);
        break;
    default:
        printf("error 4😁4");
        break;
    return open;
    }
}
int main()
{
    while (1)
    {
        menu();
    }
    return 0;
}
