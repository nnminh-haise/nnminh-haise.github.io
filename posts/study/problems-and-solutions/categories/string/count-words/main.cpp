#include <bits/stdc++.h>
#include "libraries/GeneratingMethods.h"
#include "libraries/SideFunctions.h"
#include "libraries/Constants.h"
#include "setup.cpp"

using namespace std;

class Testcase {
    private:
        string mInputData = "";
        string mOutputData = "";
        string mInputDataContent = "";
        string mOutputDataContent = "";

    public:
        Testcase (string inputData = "", string outputData = "") {
            mInputData = inputData;
            mOutputData = outputData;
        }

        void createTestcase(const int testNumber) {
            ofstream testcase_input_ostream (mInputData.c_str());
            ofstream testcase_output_ostream (mOutputData.c_str());
            ifstream testcase_input_istream (mInputData.c_str());

            makeInput(testNumber, testcase_input_ostream);
            makeOutput(testcase_input_istream, testcase_output_ostream);

            testcase_input_ostream.close();
            testcase_output_ostream.close();
            testcase_input_istream.close();

            ifstream testcase_input (mInputData.c_str());
            ifstream testcase_output (mOutputData.c_str());

            while (!testcase_input.eof()) {
                string input = "";
                getline(testcase_input, input);
                if (!(input != "\n" and input.length() > 0))
                    continue;
                mInputDataContent += input;
                bool flag = false;
                for (char chr: input)
                    if (chr == '\n')
                        flag = true;
                if (!flag)
                    mInputDataContent += '\n';
            }

            while (!testcase_output.eof()) {
                string input = "";
                getline(testcase_output, input);
                if (!(input != "\n" and input.length() > 0))
                    continue;
                mOutputDataContent += input;
                bool flag = false;
                for (char chr: input)
                    if (chr == '\n')
                        flag = true;
                if (!flag)
                    mOutputDataContent += '\n';
            }

            testcase_input.close();
            testcase_output.close();
            return;
        }

        string getInputData() {
            return mInputData;
        }

        string getOutputData() {
            return mOutputData;
        }

        string getInputDataContent() {
            return mInputDataContent;
        }

        string getOutputDataContent() {
            return mOutputDataContent;
        }

        void show() {
            cerr << "TESTCASE DATA:\n\n";
            cerr << "Input : " << mInputData << endl;
            cerr << "Content:\n";
            cerr << mInputDataContent;
            cerr << "Output: " << mOutputData << endl;
            cerr << "Content:\n";
            cerr << mOutputDataContent;
            cerr << "---\n\n";
            return;
        }
};

vector <Testcase> createTestcases() {
    cerr << "\nCREATE TESTCASE PROCESS...\n\n";

    vector <Testcase> testcase_data;

    for (int test_number = 1; test_number <= NUMBER_OF_TESTCASES; ++test_number) {
        cerr << "Making test " + getFormatedNumber(test_number, NUMBER_OF_TESTCASES) + "...\n";

        string testcase_input_filename = integerToString(test_number) + DATA_INPUT_EXTENSION;
        string testcase_output_filename = integerToString(test_number) + DATA_OUTPUT_EXTENSION;

        Testcase testcase = Testcase(testcase_input_filename, testcase_output_filename);

        testcase.createTestcase(test_number);
        testcase_data.push_back(testcase);

        cerr << "---\n";
    }

    cerr << "###\n";

    return testcase_data;
}

void createPreview(vector <Testcase> testcaseData) {
    cerr << "CREATE TESTCASES PREVIEW PROCESS...\n\n";

    ofstream preview_data (PREVIEW_TESTCASES_FILENAME.c_str());
    
    for (int test_number = 1; test_number <= NUMBER_OF_TESTCASES; ++test_number) {
        Testcase testcase = testcaseData[test_number - 1];
        testcase.show();

        preview_data << "### Test " + getFormatedNumber(test_number, NUMBER_OF_TESTCASES) + "\n";
        preview_data << testcase.getInputDataContent();
        preview_data << "---\n";
        preview_data << testcase.getOutputDataContent();
    }

    preview_data.close();

    cerr << "###\n";
    return;
}

void zipTestcases(vector <Testcase> testcaseData) {
    cerr << "\nCREATE ZIP FILE PROCESS...\n\n";

    vector <string> files;

    for (Testcase testcase: testcaseData) {
        files.push_back(testcase.getInputData());
        files.push_back(testcase.getOutputData());
    }

    string command = "zip -r " + ZIP_FILE + " ";
    for (int i = 0; i < (int)files.size(); ++i)
        command += files[i] + (i < (int)files.size() - 1 ? " " : "");

    system(command.c_str());

    cerr << "###\n";

    return;
}

void removeFiles(vector <Testcase> testcaseData) {
    cerr << "\nREMOVE TESTCASE PROCESS...\n\n";

    for (Testcase testcase: testcaseData) {
        cerr << "Removing...\n";
        string command = "rm " + testcase.getInputData() + " " + testcase.getOutputData();
        system(command.c_str());
    }

    cerr << "###\n";

    return;
}

int main(int argc, char **argv) {
    srand(time(NULL));

    vector <Testcase> testcases_data = createTestcases();
    createPreview(testcases_data);
    zipTestcases(testcases_data);
    removeFiles(testcases_data);

    return 0;
}