#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Question class
class Question {
private:
    string questionText;
    string answer;
public:
    Question(string text, string ans) {
        questionText = text;
        answer = ans;
    }

    string getQuestionText() {
        return questionText;
    }

    string getAnswer() {
        return answer;
    }
};

// Test class
class Test {
private:
    string testName;
    vector<Question> questions;
    int timer;
public:
    Test(string name, int time) {
        testName = name;
        timer = time;
    }

    void addQuestion(Question question) {
        questions.push_back(question);
    }

    void startTest() {
        cout << "Starting test: " << testName << endl;
        cout << "Timer: " << timer << " minutes" << endl;

        // Randomly select questions from the pool
        srand(time(0));
        vector<Question> selectedQuestions;
        for (int i = 0; i < questions.size(); i++) {
            int randomIndex = rand() % questions.size();
            selectedQuestions.push_back(questions[randomIndex]);
        }

        // Display and grade each question
        int marks = 0;
        for (int i = 0; i < selectedQuestions.size(); i++) {
            cout << "Question " << i + 1 << ": " << selectedQuestions[i].getQuestionText() << endl;
            string userAnswer;
            cout << "Your answer: ";
            cin >> userAnswer;

            if (userAnswer == selectedQuestions[i].getAnswer()) {
                marks++;
            }
        }

        cout << "Test completed!" << endl;
        cout << "Marks obtained: " << marks << "/" << selectedQuestions.size() << endl;
    }
};

int main() {
    // Create a test
    Test test("Math Test", 30);

    // Add questions to the test
    Question q1("What is 2 + 2?", "4");
    Question q2("What is the capital of France?", "Paris");
    Question q3("What is the square root of 16?", "4");

    test.addQuestion(q1);
    test.addQuestion(q2);
    test.addQuestion(q3);

    // Start the test
    test.startTest();

    return 0;
}
