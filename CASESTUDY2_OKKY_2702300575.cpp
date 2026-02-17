#include<stdio.h>
#include<string.h>
// Assurance Of Learning Algotithm And Programming
// Okky Sudibyo Rades - 2702300575
// 1st Semester LB95
// Case study 2 (LO 3 - L.Obj 2.2 - SO 2, 70%) :

// 8 variabel struct untuk mengisi 8 data yang berbedaku
struct okky{
	char location[69];
	char city[69];
	char price[69];
	char rooms[69];
	char bathroom[69];
	char carpark[69];
	char type[69];
	char furnish[69];
} data[4000];

// Global Variables:
int records = 0;
// ini daftar function yang aku pake buat nanti
void readfile();
void displaydata();
void searchdata(); 
void sortdata();
void exportdata();

int main()
{
	// pertama kita baca filenya supaya bisa masuk kedalam struct
	readfile();
	int option;
	do
	{
		printf("What do you want to do?\n");
		printf("1. Display data\n");
		printf("2. Search Data\n");
		printf("3. Sort Data\n");
		printf("4. Export Data\n");
		printf("5. Exit\n");
		
		do
		{
			printf("Your Choice: ");
			scanf("%d", &option); getchar();	// 	biar input yang didapat pasti 1,2,3,4,5
		}
		while(option != 1 && option != 2 && option != 3 && option != 4 && option !=5);
		
		switch(option)
		{
			case 1:
				displaydata();
				break;
			case 2:
				searchdata();
				break;
			case 3:
				sortdata();
				break;
			case 4:
				exportdata();
				break;
		}
	}
	while(option != 5);
	
	printf("Thanks for using my program!!\n");
	
// ini untuk ngesave semua file yang kita tadi modifikasi
	FILE * sayaganteng = fopen("database.csv", "w");

	
	fprintf(sayaganteng, "Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
	for(int i = 0; i < records; i++)
	{
		fprintf(sayaganteng, "%s,%s,%s,%s,%s,%s,%s,%s\n",
               data[i].location, data[i].city, data[i].price,
               data[i].rooms, data[i].bathroom, data[i].carpark,
               data[i].type, data[i].furnish);
	}
	
	fclose(sayaganteng);
	return 0;
}

void readfile()
{
	FILE * fp = fopen("database.csv", "r"); // buka file kita


	if(!fp)
	{
		printf("ERROR FILE NOT FOUND\n"); // kalau file yg kita buka gaada, kita kasi tau usernya
	}
	
	// ini buat ngeskip baca line 1 (Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish)
    fscanf(fp, "%*[^\n]\n");
	
	while(!feof(fp))
	{
		fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n", 
		&data[records].location, &data[records].city, &data[records].price, 
		&data[records].rooms, &data[records].bathroom, &data[records].carpark, 
		&data[records].type, &data[records].furnish);
		records++;
		// kita masukan semua informasi file kita kedalam struct data kita
	}
	fclose(fp);
}

void displaydata()
{
	int button;
	
	int flagrow = 0;
	do
	{
		printf("Number of rows: ");
		scanf("%d", &button); getchar();
		if(button >= 1)
		{
			flagrow = 1;
		}
		if(flagrow == 0)
		{
			printf("Number of rows must be atleast 1!\n"); // ini biar ngasi tau user salahnya dimana
		}
	}
	while(button < 1);
	// ^^ while diatas itu fungsinya biar input yang kita masukin harus minimal 1
	// ^^ kalau inputnya dibawah 1 brarti harus isi ulang inputnya
	int flag = 0;
	int temp = button;
	if(button > records)
	{
		button = records;
		flag = 1;
	}
	// ^^ fungsi if diatas itu biar kalau diminta data yang melebihi jumlah maximumnya
	// ^^ maka yang ditampilkan oleh programnya hanya jumlah maximum datanya  
	printf("\n%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
	"location", "City", "Price", "Rooms", 
	"Bathroom", "Carpark", "Type", "Furnish"); // ini untuk ngeprint judul dari columnya
	for(int i = 0 ; i < button; i++)
	{
		printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
		data[i].location, data[i].city, data[i].price, 
		data[i].rooms, data[i].bathroom, data[i].carpark, 
		data[i].type, data[i].furnish); // ini buat ngeprint semua isi data yang diminta
	}
	if(flag == 1)
	{
		printf("Maximum data have reached (%d data)\n", records); // ini buat ngasi tau user yang minta kebanyakan data
	}
	printf("\n");
}

void searchdata()
{
	char column[69];
	char find[60];
//	printf("===SEARCH DATA===\n");
	
	do
	{
		printf("Choose column: ");
		scanf("%[^\n]", column);
        getchar();	
        if(	strcmpi(column, "location") != 0 && strcmpi(column, "city") &&		// aku pake strcmpi kesemua bagian 
			strcmpi(column, "price") != 0 	&& strcmpi(column, "rooms") &&		// supaya inputnya tidak case sensitive
			strcmpi(column, "bathroom") != 0 && strcmpi(column, "carpark") &&	// dan supaya untuk input" jadi gampang
			strcmpi(column, "type") != 0 	&& strcmpi(column, "furnish"))
			{
				printf("Column name is incorrect\n");
				printf("Column list: \n");
				printf("- Location\n");
				printf("- City\n");
				printf("- Price\n");
				printf("- Rooms\n");
				printf("- Bathroom\n");
				printf("- Carpark\n");
				printf("- Type\n");
				printf("- Furnish\n");
			}
	}	
	while(	strcmpi(column, "location") != 0 && strcmpi(column, "city") &&
			strcmpi(column, "price") != 0 	&& strcmpi(column, "rooms") &&
			strcmpi(column, "bathroom") != 0 && strcmpi(column, "carpark") &&
			strcmpi(column, "type") != 0 	&& strcmpi(column, "furnish"));
	// ^^ while ini fungsinya biar input yang diterima hanya column yang disediakan
	// ^^ jika input yang diberi selain dari column, maka kita minta untuk menulis ulang columnya
	printf("What data do you want to find? ");
	scanf("%[^\n]", find); getchar();
	
	int flag = 0;
	
	if(strcmpi(column, "location") == 0) // pertama kita cari tau apakah columnya sesuai atau tidak
	{
		for(int i = 0; i<records; i++) 
		{
			if(strcmpi(find, data[i].location) == 0) // setelah itu kita cari disemua data apakah yang kita cari itu hasilnya sama atau tidak
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				} // kalau hasilnya sama brarti kita print aja
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n"); // kalau tidak ada data yang sama maka kita kasi tau user kalo datanya emang gaada
		}
		printf("===============\n"); // pembatas biar bacanya gampang
	} // else if dibawah sama saja bedanya columnya yang beda (location, city, dll)
	else if(strcmpi(column, "city") == 0)
	{
		for(int i = 0; i<records; i++)
		{
			if(strcmpi(find, data[i].city) == 0)
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				}
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n");
		}
		printf("===============\n");
	}
	else if(strcmpi(column, "price") == 0)
	{
		for(int i = 0; i<records; i++)
		{
			if(strcmpi(find, data[i].price) == 0)
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				}
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n");
		}
		printf("===============\n");
	}
	else if(strcmpi(column, "rooms") == 0)
	{
		for(int i = 0; i<records; i++)
		{
			if(strcmpi(find, data[i].rooms) == 0)
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				}
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n");
		}
		printf("===============\n");
	}
	else if(strcmpi(column, "bathroom") == 0)
	{
		for(int i = 0; i<records; i++)
		{
			if(strcmpi(find, data[i].bathroom) == 0)
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				}
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n");
		}
		printf("===============\n");
	}
	else if(strcmpi(column, "carpark") == 0)
	{
		for(int i = 0; i<records; i++)
		{
			if(strcmpi(find, data[i].carpark) == 0)
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				}
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n");
		}
		printf("===============\n");
	}
	else if(strcmpi(column, "type") == 0)
	{
		for(int i = 0; i<records; i++)
		{
			if(strcmpi(find, data[i].type) == 0)
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				}
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n");
		}
		printf("===============\n");
	}
	else if(strcmpi(column, "furnish") == 0)
	{
		for(int i = 0; i<records; i++)
		{
			if(strcmpi(find, data[i].furnish) == 0)
			{
				if(flag == 0)
				{
					printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
					"location", "City", "Price", "Rooms", 
					"Bathroom", "Carpark", "Type", "Furnish");
					flag = 1;
				}
				printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n", 
				data[i].location, data[i].city, data[i].price, 
				data[i].rooms, data[i].bathroom, data[i].carpark, 
				data[i].type, data[i].furnish);
			}
		}
		if(flag == 0)
		{
			printf("Data Not Found!\n");
		}
		printf("===============\n");
	}
	
}

void sortdata() 
{
    char column[69];
    char ascdsc[69];
    
    do
	{
		printf("Choose column: ");
		scanf("%[^\n]", column);
        getchar();	
        if(	strcmpi(column, "location") != 0 && strcmpi(column, "city") &&
			strcmpi(column, "price") != 0 	&& strcmpi(column, "rooms") &&
			strcmpi(column, "bathroom") != 0 && strcmpi(column, "carpark") &&
			strcmpi(column, "type") != 0 	&& strcmpi(column, "furnish"))
			{
				printf("Column name is incorrect\n");
				printf("Column list: \n");
				printf("- Location\n");
				printf("- City\n");
				printf("- Price\n");
				printf("- Rooms\n");
				printf("- Bathroom\n");
				printf("- Carpark\n");
				printf("- Type\n");
				printf("- Furnish\n");
			}
	}	
	while(	strcmpi(column, "location") != 0 && strcmpi(column, "city") &&
			strcmpi(column, "price") != 0 	&& strcmpi(column, "rooms") &&
			strcmpi(column, "bathroom") != 0 && strcmpi(column, "carpark") &&
			strcmpi(column, "type") != 0 	&& strcmpi(column, "furnish"));
	// ^^ while ini fungsinya biar input yang diterima hanya column yang disediakan
	// ^^ jika input yang diberi selain dari column, maka kita minta untuk menulis ulang columnya
	do
	{
		printf("Sort Ascending or Descending? (asc/dsc): ");
		scanf("%[^\n]", ascdsc);
		getchar();
		if(	strcmpi(ascdsc, "asc") != 0 && strcmpi(ascdsc, "ascending") != 0 &&
			strcmpi(ascdsc, "dsc") != 0 && strcmpi(ascdsc, "descending") != 0)
			{
				printf("sorting name is incorrect\n");
				printf("sorting list:\n");
				printf("- asc\n");
				printf("- ascending\n");
				printf("- dsc\n");
				printf("- descending\n");
			}
	}
	while(	strcmpi(ascdsc, "asc") != 0 && strcmpi(ascdsc, "ascending") != 0 &&
			strcmpi(ascdsc, "dsc") != 0 && strcmpi(ascdsc, "descending") != 0);
    // ^^ while ini fungsinya biar input yang diterima hanya kata asc, ascending, dsc, dan descending
	// ^^ jika input yang diberi selain dari itu, maka kita minta untuk menulis ulang inputnya
	int sortflag = 0;
	
	// bubble sort
	for(int i = 0; i < records; i++)
	{
		for(int j = 0; j < records - i - 1; j++)
		{
			int sort = 0;
			if(strcmpi(column, "location") == 0) // ini untuk mengetahui column kita berada dibagian mana
			{
				sort = strcmpi(data[j].location, data[j+1].location);
				// setelah column diketahui, kita compare string data ke j dan j + 1 lalu hasil comparenya dimasukin ke int sort
			}
			else if(strcmpi(column, "city") == 0)
			{
				sort = strcmpi(data[j].city, data[j+1].city);
			}
			else if(strcmpi(column, "price") == 0)
			{
				sort = strcmpi(data[j].price, data[j+1].price);
			}
			else if(strcmpi(column, "rooms") == 0)
			{
				sort = strcmpi(data[j].rooms, data[j+1].rooms);
			}
			else if(strcmpi(column, "bathroom") == 0)
			{
				sort = strcmpi(data[j].bathroom, data[j+1].bathroom);
			}
			else if(strcmpi(column, "carpark") == 0)
			{
				sort = strcmpi(data[j].carpark, data[j+1].carpark);
			}
			else if(strcmpi(column, "type") == 0)
			{
				sort = strcmpi(data[j].type, data[j+1].type);
			}
			else if(strcmpi(column, "furnish") == 0)
			{
				sort = strcmpi(data[j].furnish, data[j+1].furnish);
			}
			
			if(( strcmpi(ascdsc, "asc") == 0 && sort > 0) || 		// ini untuk mengetahui sortingan kita ascending atau descending
				(strcmpi(ascdsc, "ascending") == 0 && sort > 0) || 	// kalau ascending brarti hasil dari int sort harus > 0
				(strcmpi(ascdsc, "dsc") == 0 && sort < 0) || 		// kalau descending brarti hasil dari int sort harus < 0
				(strcmpi(ascdsc, "descending") == 0 && sort < 0))
			{
				// melakukan swapping algorithm untuk bubblesort
				struct okky temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}	
		}
	}

    // setelah semua data di sort sesuai selera, kita print 10 data pertama
    printf("\n%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n",
           "location", "City", "Price", "Rooms",
           "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0; i < 10 && i < records; i++)
    {
        printf("%-27s%-18s%-13s%-9s%-12s%-12s%-13s%-13s\n",
               data[i].location, data[i].city, data[i].price,
               data[i].rooms, data[i].bathroom, data[i].carpark,
               data[i].type, data[i].furnish);
    }
    printf("\n");
}

void exportdata()
{
	char filename[69];
	printf("File name: ");
	scanf("%[^\n]", &filename); getchar();
	strcat(filename, ".csv"); // ini buat nambah ".csv" dibelakang inputan kita >> misal okky menjadi okky.csv
	
	//ini buat buka file dan kita beri mode write(w)
	FILE *newfile = fopen(filename, "w");
	
	// print lagi Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish
	// ^^ itu karena aku ga read dan masukin ke struct jadi harus print ulang
	fprintf(newfile, "Location 1,Location 2,Price,Rooms,Bathrooms,CarParks,Type,Furnish\n");
	for(int i = 0; i < records; i++)
	{
		fprintf(newfile, "%s,%s,%s,%s,%s,%s,%s,%s\n",
               data[i].location, data[i].city, data[i].price,
               data[i].rooms, data[i].bathroom, data[i].carpark,
               data[i].type, data[i].furnish); // print ke file semua data yang tadi sudah dibaca di struct
	}
	
	fclose(newfile);
	// tutup file dan beri konfirmasi kalau datanya sudah selesai dibaca
	printf("Data Successfully Written to file %s!\n\n", filename);
}

// Thank you for lending your time to see my code :D
// have a nice day!!
