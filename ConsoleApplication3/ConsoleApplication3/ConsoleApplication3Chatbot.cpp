// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to preprocess input text (e.g., removing punctuation, converting to lowercase)
string preprocessInput(const string& input) {
	string processedInput = input;
	// Convert input to lowercase
	transform(processedInput.begin(), processedInput.end(), processedInput.begin(), ::tolower);
	// Remove punctuation
	processedInput.erase(remove_if(processedInput.begin(), processedInput.end(), ::ispunct), processedInput.end());
	return processedInput;
}

// Function to perform sentiment analysis on input text
string analyzeSentiment(const string& input) {
	// Placeholder sentiment analysis (always returns neutral)
	return "neutral";
}

// Function to generate a response based on input text
string generateResponse(const string& input) {
	// Placeholder responses based on sentiment
	if (input.find("hello") != string::npos || input.find("hi") != string::npos)
		return "Hi there!";
	else if (input.find("how can chatbot be used") != string::npos)
		return "Chatbots can be used to communicate with people, answer common questions, and perform specific tasks they were programmed for.";
	else if (input.find("goodbye") != string::npos || input.find("bye") != string::npos)
		return "Goodbye! Have a great day.";
	else
		return "I'm sorry, I didn't understand that.";
}

int main() {
	cout << "AI Chatbot: Hello! How can I assist you today?" << endl;

	string input;
	while (true) {
		cout << "User: ";
		getline(cin, input); // Get user input

		// Preprocess input
		string preprocessedInput = preprocessInput(input);

		// Analyze sentiment
		string sentiment = analyzeSentiment(preprocessedInput);

		// Generate response based on sentiment
		string response = generateResponse(preprocessedInput);

		// Output response
		cout << "AI Chatbot: " << response << endl;

		// End conversation if user says goodbye
		if (preprocessedInput == "goodbye") {
			break;
		}
	}

	return 0;
}

