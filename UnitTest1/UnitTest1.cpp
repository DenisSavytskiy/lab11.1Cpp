#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <string>
#include "../AP_Lab№11.1 C++/AP_Lab№11.1 C++.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // Тестування на файлі з відомою кількістю входжень "while"
        TEST_METHOD(TestWhileOccurrencesInFile)
        {
            // Створюємо тестовий файл
            std::string testFilename = "test_while_file.txt";
            std::ofstream testFile(testFilename);
            testFile << "This is a test while file\n";
            testFile << "while testing is important\n";
            testFile << "Another while test case\n";
            testFile.close();

            // Перевіряємо очікувану кількість входжень
            int expectedCount = 3;
            int actualCount = CountWhileOccurrences(testFilename);

            // Перевірка результату
            Assert::AreEqual(expectedCount, actualCount);
        }

        // Тестування на порожньому файлі
        TEST_METHOD(TestEmptyFile)
        {
            std::string emptyFilename = "empty_file.txt";
            std::ofstream emptyFile(emptyFilename);
            emptyFile.close();

            int expectedCount = 0;
            int actualCount = CountWhileOccurrences(emptyFilename);

            Assert::AreEqual(expectedCount, actualCount);
        }

        // Тестування на файлі без входжень "while"
        TEST_METHOD(TestNoWhileOccurrences)
        {
            std::string noWhileFilename = "no_while_file.txt";
            std::ofstream noWhileFile(noWhileFilename);
            noWhileFile << "This is a test file\n";
            noWhileFile.close();

            int expectedCount = 0;
            int actualCount = CountWhileOccurrences(noWhileFilename);

            Assert::AreEqual(expectedCount, actualCount);
        }
    };
}