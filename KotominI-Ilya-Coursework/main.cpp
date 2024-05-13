#include <iostream>

using namespace std;

#pragma region LIST

struct list_element
{
    int key;
    list_element* next;
    static list_element* add(list_element* start, int number);
    static void print_list(const list_element* start);
    static list_element* reverse_list(list_element* start);
    static list_element* sum_two_lists(const list_element* num1, const list_element* num2);
} *start1 = nullptr, *start2 = nullptr;

list_element* list_element::add(list_element* start, const int number)
{
    if (number > 9 || number < 0)
    {
        cout << number << " SKIPPED! Number " << number << " can NOT be added because it MUST be from 1 to 9 and positive!\n";
        return start;
    }

    const auto element = new list_element;
    element->key = number;
    element->next = start;
    return element;
}

void list_element::print_list(const list_element* start)
{
    const list_element* iterator = start;
    while (iterator != nullptr)
    {
        cout << iterator->key << ' ';
        iterator = iterator->next;
    }
}

list_element* list_element::reverse_list(list_element* start)
{
    // ReSharper disable once CppInitializedValueIsAlwaysRewritten
    list_element *prev = nullptr, *current = start, *next = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

list_element* list_element::sum_two_lists(const list_element* num1, const list_element* num2)
{
    list_element* result = nullptr;
    int carry = 0;

    const list_element* ptr1 = num1;
    const list_element* ptr2 = num2;

    while (ptr1 != nullptr || ptr2 != nullptr || carry != 0)
    {
        int digit_sum = carry;
        if (ptr1 != nullptr)
        {
            digit_sum += ptr1->key;
            ptr1 = ptr1->next;
        }
        if (ptr2 != nullptr)
        {
            digit_sum += ptr2->key;
            ptr2 = ptr2->next;
        }

        carry = digit_sum / 10;
        digit_sum %= 10;
        result = add(result, digit_sum);
    }

    return result;
}

#pragma endregion

void main()
{
    cout << "Enter a digit (0-9) for List 1 (-1 to finish): ";
    int num;
    while (cin >> num)
    {
        if (num <= 0) break;
        start1 = list_element::add(start1, num);
        cout << "Enter a digit (0-9) for List 1 (-1 to finish): ";
    }

    cout << "Enter a digit (0-9) for List 2 (-1 to finish): ";
    while (cin >> num)
    {
        if (num <= 0) break;
        start2 = list_element::add(start2, num);
        cout << "Enter a digit (0-9) for List 2 (-1 to finish): ";
    }

    const list_element* sum = list_element::sum_two_lists(start1, start2);
    cout << "\nList 1: ";
    list_element::print_list(list_element::reverse_list(start1));
    cout << "\nList 2: ";
    list_element::print_list(list_element::reverse_list(start2));
    
    cout << "\nSum: ";
    list_element::print_list(sum);
    cout << endl;

    system("pause>nul");  // NOLINT(concurrency-mt-unsafe)
}
