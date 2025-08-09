# Travel-Booking-System

Welcome to the Travel Booking System, an interactive C program designed for booking city tours.  
This application allows users to seamlessly book, view, and cancel their vacation plans, offering both pre-planned itineraries and customizable travel options.

---

## Features

* **Book a Trip**
    * **City Selection:** Choose from a list of international cities like Paris, Dubai, and Tokyo.
    * **Pre-Planned Trips:** Select from complete travel packages designed for various budgets and themes.
    * **Custom Plans:** Tailor your vacation by individually booking hotels or activities.
* **View Bookings**
    * Easily display a list of all your current bookings. All booking information is saved to a `bookings.txt` file.
* **Cancel Bookings**
    * Flexibility to cancel a single, specific booking or clear all your travel plans at once.
---

### **Operational Flow**

1.  **Welcome & Main Menu:** The program starts with a welcome message and presents a main menu with four options: Book a trip, View bookings, Cancel bookings, or Exit.
2.  **Booking a Trip:**
    * The user selects a city and then chooses between a pre-planned trip or a custom plan.
    * **Pre-planned:** The user picks a trip from a list and confirms the booking.
    * **Custom:** The user books a hotel by providing start and end dates or an activity by providing a single date.
    * The system then collects and validates passenger details (name, age, mobile number) for the number of travelers specified.
3.  **Viewing Bookings:** This option displays all saved bookings from `bookings.txt`.
4.  **Cancelling Bookings:** Users can opt to remove a specific booking from a numbered list or cancel all bookings at once.
5.  **Exit:** Terminates the application cleanly.

### **Technical Components**

* **Language:** C-Programming
* **Data Storage:** A text file (`bookings.txt`) is used to store and manage all booking details.
* **Core Logic:** The program utilizes functions for modularity, `if-else` and `switch` statements for control flow, and 2D arrays to manage trip and city data.
* **Input Validation:** Robust functions are in place to validate user inputs such as dates (`isValidDate`), age (`getValidAge`), and mobile numbers (`getValidMobile`), ensuring data integrity.

## How the Technical Components Work

The project is built on a foundation of core C programming concepts that work together to create a functional and interactive application.

**Core Logic and Structure:** The program's flow is managed by `if-else` and `switch` statements within a main loop, guiding you through menus for booking, viewing, or canceling trips. This entire structure is organized into separate functions (e.g., `viewBookings`, `cancelBookings`), making the code modular and easier to manage. All bookings are persistently stored in and retrieved from a simple text file named `bookings.txt`, using standard file-handling functions like `fopen()` to open it, `fgets()` to read from it, and `fclose()` to close it.

**Data Handling:** Key limitations, such as the number of cities or trips, are defined using `#define` constants for easy modification. The various trip options, hotels, and activities for each city are stored in 2D arrays, which provide an organized way to manage this structured data. When you make a booking, your details are handled using C's string manipulation functions like `sscanf` and `strlen` to process and validate the input.

**Input Validation:** To ensure data integrity, dedicated functions rigorously check all user input. The `isValidDate` function, for instance, checks that a date is in the correct `YYYY-MM-DD` format, is a valid calendar date (accounting for leap years), and is not in the past. Similarly, `getValidAge` ensures the age is within a realistic range, and `getValidMobile` verifies that the mobile number contains only digits. This robust validation prevents errors and ensures the data saved to `bookings.txt` is reliable.
