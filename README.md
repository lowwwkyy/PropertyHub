# PropertyHub - Malaysia Property Database Manager

A lightweight console-based property data management system built with C, designed to handle Malaysian real estate listings efficiently.

## About The Project

This project was developed as part of the **Assurance of Learning for Algorithm and Programming** course at BINUS University.

### The Problem

Malaysia's property market, especially in Kuala Lumpur, has thousands of listings spread across different locations with varying prices, room counts, and furnishing statuses. For potential buyers, investors, or researchers, manually sifting through massive datasets to find specific properties or analyze market trends can be overwhelming and time-consuming.

This program provides a simple yet effective solution to:
- Quickly browse through property listings
- Search for properties based on specific criteria (location, price range, number of rooms, etc.)
- Sort data to identify trends (cheapest/most expensive, areas with most listings)
- Export filtered/sorted data for further analysis

### Dataset

The included database contains **3,940+ property listings** from various areas in Kuala Lumpur, Malaysia, including:
- Mont Kiara, Cheras, Kepong, Bukit Jalil, KLCC, Sentul, Setapak, and more

Each record includes: Location, City, Price (MYR), Rooms, Bathrooms, Car Parks, Property Type, and Furnishing Status.

## Features

- **Display Data** - View property listings with customizable row count
- **Search Data** - Find properties by any column (location, city, price, rooms, bathroom, carpark, type, furnish)
- **Sort Data** - Sort listings in ascending or descending order by any column using bubble sort algorithm
- **Export Data** - Save current dataset to a new CSV file
- **Auto-Save** - All modifications are automatically saved back to the database on exit

## Tech Stack

| Component | Technology |
|-----------|------------|
| Language | C (compiled as C++) |
| Data Storage | CSV (Comma-Separated Values) |
| Data Structure | Struct Array |
| Sorting Algorithm | Bubble Sort |
| I/O | Standard C Library (stdio.h) |
| String Handling | string.h |

## Getting Started

### Prerequisites

- Any C/C++ compiler (GCC, MinGW, or Visual Studio)

### Installation

1. Clone the repository
   ```bash
   git clone https://github.com/yourusername/PropertyHub.git
   ```

2. Compile the program
   ```bash
   gcc CASESTUDY2_OKKY_2702300575.cpp -o PropertyHub
   ```

3. Run the executable
   ```bash
   ./PropertyHub
   ```

### Usage

```
What do you want to do?
1. Display data
2. Search Data
3. Sort Data
4. Export Data
5. Exit
Your Choice: _
```

**Example - Searching for properties in Mont-Kiara:**
```
Choose column: location
What data do you want to find? Mont-Kiara
```

**Example - Sorting by price (ascending):**
```
Choose column: price
Sort Ascending or Descending? (asc/dsc): asc
```

## Project Structure

```
PropertyHub/
├── CASESTUDY2_OKKY_2702300575.cpp   # Main source code
├── database.csv                       # Property dataset (3940+ records)
└── README.md                          # Project documentation
```

## Author

**Okky Sudibyo Rades** - 2702300575  

---

*This project was created for educational purposes as part of the Algorithm and Programming course.*
