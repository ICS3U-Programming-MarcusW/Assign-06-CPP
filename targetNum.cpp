// Copyright (c) 2022 Marcus Wehbi All rights reserved.
//
// Created by: Marcus Wehbi
// Created on: Dec 16 2022
// This program asks the user to enter a list of numbers and a target number
// The program then prints the first and last occurrence of this number

#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

// Function to find the first and last occurrences of the target number
// numbers = a list of integers to search through
// target = the target number to search for
// num = number to compare to the target number
void FindOccurrences(const std::list<int>& numbers,
int target, int& first, int& last) {
    // Find the first occurrence of the target number
    // Set first to -1 in case the target number is not found
    first = -1;
    // Initialize the index to 0
    int index = 0;
    // Iterate through the list to find the target number
    for (int num : numbers) {
        // If the target number is found, assign index to the 'first'
        // ...variable which signifies the first index
        if (num == target) {
            first = index;
            // Break out of the loop
            break;
        }
        // Increment the index counter after each iteration
        index++;
    }

    // Find the last occurrence of the target number
    // Set last to -1 in case the target number is not found
    last = -1;
    // Initialize the index to 0
    index = 0;
    // Iterate through the list to find the target number
    for (int num : numbers) {
        // If the target number is found, assign index to the 'last'
        // ...variable which signifies the last index
        if (num == target) {
            last = index;
        }
        // Increment the index counter after each iteration
        index++;
    }
}

// Function to find all the indices of the target number
// numbers = a list of integers to search through
// target = the target number to search for
// indices = a list to store the indices of the target number
void FindIndices(const std::list<int>& numbers, int target,
std::vector<int>& indices) {
    // Clear the list of indices
    indices.clear();
    // Find all the occurrences of the target number
    // Initialize the index to 0
    int index = 0;
    // Use a for each loop to iterate through the list of integers
    for (int num : numbers) {
        // If the target number is found, add the index to the list
        if (num == target) {
            // Add the index to the list
            indices.push_back(index);
        }
        // Increment the index counter after each iteration
        index++;
    }
}

// Function to find the median value in the list
// numbers = a list of integers to find the median of
// median = a variable to store the median value
void FindMedian(const std::list<int>& numbers, double& median) {
    // Convert the list to a vector
    std::vector<int> vec(numbers.begin(), numbers.end());
    // Sort out the vector
    std::sort(vec.begin(), vec.end());
    // Find the median value
    size_t size = vec.size();
    if (size % 2 == 0) {
        // If the size of the vector is even, the median is the
        // ...average of the two middle values
        // Formula to calculate median when their is an even number
        // ...of numbers in the list
        median = (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
    } else {
        // If the size of the vector is odd, the median is the middle value
        // Formula to get the middle value
        median = vec[size / 2];
    }
}

// Function to get all inputs, error check, and output the results
int main() {
    // Initialize the variables
    std::list<int> numbers;
    std::string input;
    // Explain what the program does, to the user
    std::cout << "This program finds the first and last occurrences of ";
    std::cout << "an integer in a list. It also finds all indices of the ";
    std::cout << "integer and the median value of the list.";
    std::cout << "In order for this program to work, you must ensure that you";
    std::cout << " are entering a sorted list, and each integer is separated ";
    std::cout << "by spaces. Here is a sample input: 1 5 6 6 6 7" << std::endl;
    std::cout << "\n";
    std::cout << "\n";
    // Get a sorted list from the user
    std::cout << "Enter a sorted list of numbers: ";
    // Read the entire line of input (including spaces)
    try {
        std::getline(std::cin, input, '\n');
        // Use a stringstream to parse the input string
        // Create a stringstream object
        std::stringstream stream(input);
        // Variable to store the extracted integer
        int num;
        // Extract integers from the stream until there are none left
        // Use a while loop to do this
        while (stream >> num) {
            // Add the extracted integer to the list
            numbers.push_back(num);
        }
        // Check the status of the stream
        if (!stream.eof()) {
            // Message for invalid input
            std::cout << "Please enter a valid list of numbers." << std::endl;
            return 1;
        }
    } catch (std::invalid_argument) {
        // Message for invalid input
        std::cout << "Please enter a valid number." << std::endl;
    }
    // Get the targeted number from the user
    std::cout << "Enter the targeted number: ";
    int target;
    std::cin >> target;
    // Find the first and last occurrences of the target number
    int first, last;
    // Call function to get the first and last occurrences of
    // ...a number in a list
    FindOccurrences(numbers, target, first, last);
    // Call function to find all the indices of the target number
    std::vector<int> indices;
    FindIndices(numbers, target, indices);
    // Call function to find the median value of the list
    double median;
    FindMedian(numbers, median);
    // Print the results
    // First and last occurrence of a target number
    std::cout << "The first occurrence of " << target <<
    " is at index " << first << "." << std::endl;
    std::cout << "The last occurrence of " << target <<
    " is at index " << last << "." << std::endl;
    // All indices of many target numbers
    std::cout << "The indices of " << target << " are: ";
    for (int index : indices) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
    // Median value of the list of integers
    std::cout << "The median value of the list is: " << median
    << "." << std::endl;
}
