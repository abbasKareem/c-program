#include <iostream>
#include <vector>


void printVector(const std::vector<int> my_vector);
void printChoose();
void addNumber(std::vector<int> &numbers, int number_to_add);
bool displayMean(const std::vector<int> numbers);
bool displaySmallest(const std::vector<int> numbers);
bool displayLargest(const std::vector<int> numbers);
bool isEmpty(const std::vector<int> numbers);
bool clearList(std::vector<int> &numbers);


using namespace std;

int main() {
    bool exit {false};
    vector<int> numbers {};
    char choose {};
    int number_to_add {};

    while(!exit) {
        printChoose();
        cin>> choose;
        switch(choose) {
            case 'Q':
            case 'q':
                exit = true;
                break;
            case 'P':
            case 'p':
                printVector(numbers);
                break;
            case 'a':
            case 'A':
                cout<<"Enter number to add to victor: ";
                cin>> number_to_add;
                if(cin.fail()) {
                    cout<< "\nNot allowed, please select an intger number. EXIT"<< endl;
                    exit = true;
                } else {
                    addNumber(numbers, number_to_add);
                    break;
                }
            case 'm':
            case 'M':
                displayMean(numbers);
                break;
            case 's':
            case 'S':
                displaySmallest(numbers);
                break;
            case 'l':
            case 'L':
                displayLargest(numbers);
                break;
            case 'r':
            case 'R':
                clearList(numbers);
                break;
            default:
                cout<< "\n Uknow selection, please try again \n";
        }
        
    }
    
    return 0;
}

void printChoose() {
    cout<<endl;
    cout<<"P- print all numbers"<< endl;
    cout<<"A- add a number"<< endl;
    cout<<"M- display mean of numbers"<< endl;
    cout<<"S- display smallest number"<< endl;
    cout<<"L- display largest number"<< endl;
    cout<<"C- Remove all the elements in the list!"<< endl;
    cout<<"Q- Quit"<< endl;
    cout<< "Choose: ";
}

void printVector(vector<int> my_vector){
    cout<< "\n [ ";
    for(auto val: my_vector) 
        cout<< val << " " ;
    cout<< "]"<< endl ;
}

void addNumber(vector<int> &numbers, int number_to_add){
        numbers.push_back(number_to_add);
        cout<< number_to_add << "added Successfully!"<< endl;
}

bool displayMean(vector<int> numbers){
    if(isEmpty(numbers)){
        cout<< "the list is empty"<< endl;
        return false;
    }
    else {
        double avg {};
        int sum {};
        for(auto val: numbers)
            sum = sum + val;
        avg = static_cast<double> (sum) / numbers.size();
        cout<< "\n The mean of numbers is: "<< avg<< endl;
        return true;
    }
}

bool displaySmallest(vector<int> numbers){
    
    if(isEmpty(numbers)) {
        cout<<"\n the list is empty"<< endl;
        return false;
    }
    else{
        int smallest = numbers.at(0);
        for(size_t i {0}; i < numbers.size() - 1; ++i){
            if (smallest > numbers[i+1]){
                smallest = numbers[i+1];
            }
        }
        cout <<endl << "Smallest is: "<< smallest << endl;
        return true;
    }
}

bool displayLargest(const std::vector<int> numbers){

    if(isEmpty(numbers)){
        cout<< "the list is empty" << endl;
        return false;
    }
    else{
        int largest = numbers.at(0);
        for(size_t i {0}; i < numbers.size() - 1; ++i){
            if (largest < numbers[i+1]){
                largest = numbers[i+1];
            }
        }
        cout <<endl << "Largest is: "<< largest << endl;
        return true;
    }
    
}

bool clearList(vector<int> &numbers){
    if(isEmpty(numbers)){
        cout<< "Your list is already empty!"<< endl;
        return false;
    } else {
        numbers.clear();
        cout<< "Clear the list\n";
        return true;
    }
}

bool isEmpty(vector<int> numbers){
    if(numbers.size() == 0 )
        return true;
    else
        return false;
}
