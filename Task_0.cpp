#include <iostream>
#include <string>
#include <cmath>


void IntoReverseCode (std::string& str);
double Calculations (std::string str);
void Inicialization (int* number, int count ,std::string str);
int Delenie (int* number, std::string& res1, int count);
void IntoNumArr (int* number_Reverse, int count ,std::string res1);
void OurArr(int* arr, int count);
void SumInReverse(int* number1_Reverse,int* number2_Reverse,int count);
void IntoReverseCode (int* arr, int count);
void TransformIntoAdditionalCode (int* arr, int count);
int SizeofNum(std::string num);
void Transformation (std::string num, std::string* number);
void Matrix (std::string** matrix, long long notation);
bool InputCheck (std::string** matrix, std::string*number, long long notation, int size);
void Summary(std::string** matrix, std::string* number1, std::string* number2, std::string* Sum, long long notation, int size);
void Raznost(std::string** matrix, std::string* number1, std::string* number2, std::string* Sum, long long notation, int size);
int Compare(std::string** matrix, std::string* number1, std::string* number2, long long notation, int size);
void Kratnost29(std::string& number , int length);
void Kratnost7(std::string& number , int length);
void Kratnost149(std::string& number , int length);
int FindPoison (int* barrels);

int main () {
  std::cout << "введите номер задания, которое хотите запустить(1-5): " << '\n';

  int Task = 0;
  while (!(std::cin >> Task) || (std::cin.peek() != '\n') || Task < 1 || Task > 5) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "неправильный ввод(1-240):  " << std::endl;
  }
  if (Task == 1) {
    std::cout << "без посторонних симолов введите число в двоичном виде и обратном представлении: "  << '\n';

    std::string str;
    int count = 0, check = 0;
    for (;;) {
      check = 0;
      std::getline(std::cin, str);
      while (count < str.length() - 1) {
        if (str[count] != '0' && str[count] != '1') {
          str.clear();
          count = 0;
          check = 1;
          std::cout <<"неправильный ввод(только 0 или 1): " << '\n';
          break;
        }
        ++count;
      }
      if (check == 0) {
        break;
      }
    }
    IntoReverseCode(str);

    long double Sum = 0;
    if (str[0] == '1') {
      Sum = -Calculations(str);
    }
    else {
      Sum = Calculations(str);
    }

    std::cout << "в десятичной системе счисления введенное число равно: " << Sum << std::endl;
    
    return 0;
  }
  else if (Task == 2) {
    std::cout << "без посторонних симолов введите первое число в десятичном виде: "  << '\n';
    getchar();
    std::string str1; //ввод
    std::string res1; //результат деления
    int count1 = 0, sign1 = 0;;
    int check1 = 0;
    for (;;) {
      check1 = 0;
      std::getline(std::cin, str1);
      while (count1 < str1.length()) {
        if (isdigit(str1[count1]) != 1 && str1[count1] != '-') {
          str1.clear();
          count1 = 0;
          check1 = 1;
          std::cout <<"неправильный ввод: " << '\n';
          break;
        }
        ++count1;
      }
      if (check1 != 1) {
        break;
      }
    }
    if (str1[0] == '-') {
      sign1 = 1;
      str1.erase(0, 1);
    }
    int* number1 = new int[str1.length()];
    Inicialization(number1, str1.length(), str1);
    Delenie(number1, res1, str1.length());
    

    // ввод и обработка второго числа до получения строки в еще не перевернутом виде без знаковго бита
    std::cout << "без посторонних симолов введите первое число в десятичном виде: "  << '\n';

    std::string str2; //ввод
    std::string res2; //результат деления
    count1 = 0;
    check1 = 0;
    int sign2 = 0;
    for (;;) {
      check1 = 0;
      std::getline(std::cin, str2);
      while (count1 < str2.length()) {
        if (isdigit(str2[count1]) != 1 && str2[count1] != '-') {
          str2.clear();
          count1 = 0;
          check1 = 1;
          std::cout <<"неправильный ввод: " << '\n';
          break;
        }
        ++count1;
      }
      if (check1 != 1) {
        break;
      }
    }
    if (str2[0] == '-') {
      sign2 = 1;
      str2.erase(0, 1);
    }
    int* number2 = new int[str2.length()];
    Inicialization(number2, str2.length(), str2);
    Delenie(number2, res2, str2.length());

    if (res1.length() > res2.length()) {
      res2.append(res1.length() - res2.length(),'0');
    }
    else if (res2.length() > res1.length()) {
      res1.append(res2.length() - res1.length(),'0');
    }
    res1.push_back('0');
    res2.push_back('0');
    if (sign1 == 0) {
        res1.push_back('0');
      }
      else {
        res1.push_back('1');
      }
      if (sign2 == 0) {
        res2.push_back('0');
      }
      else {
        res2.push_back('1');
    }
    int* number1_Reverse = new int[res1.length()];
    int* number2_Reverse = new int[res2.length()];
    std::reverse(res1.begin(), res1.end());
    std::reverse(res2.begin(), res2.end());
    std::cout << "num1(в прямом коде) = " << res1 << "    num2(в прямом коде) = " << res2 << '\n';
    IntoNumArr(number1_Reverse,res1.length(),res1);
    if (sign1 == 1) {
      IntoReverseCode(number1_Reverse,res1.length());
    }
    IntoNumArr(number2_Reverse,res2.length(),res2);
    if (sign2 == 1) {
      IntoReverseCode(number2_Reverse,res2.length());
    }
    std::cout << "num1(в обратном коде) = " ;
    OurArr(number1_Reverse,res1.length());
    std::cout << "num2(в обратном коде) = " ;
    OurArr(number2_Reverse,res2.length());

    SumInReverse(number1_Reverse, number2_Reverse, res1.length());

    std::cout << "Sum(в обратном коде): ";
    OurArr(number1_Reverse,res1.length());

    TransformIntoAdditionalCode(number1_Reverse,res1.length());
    std::cout << "Sum(в дополнительном коде): ";
    OurArr(number1_Reverse,res1.length());
    
    
    delete[] number2_Reverse;
    number2_Reverse = nullptr;
    delete[] number1_Reverse;
    number1_Reverse = nullptr;
    delete[] number2;
    number2 = nullptr;
    delete[] number1;
    number1 = nullptr;
    
    return 0;
  }
  else if (Task == 3) {
    start://возврат в случае неправильного ввода
    std::cout << "введите систему счисления в которой будет производится сложение и вычитание: " << '\n';
    long long notation;
    while (!(std::cin >> notation) || (std::cin.peek() != '\n') || notation < 2 || notation > 9999000) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод(<2):  " << std::endl;
    }
    getchar();
    std::cout << "введите первое число, в той системе счисления, которую вы задали(ввод осуществлять по 1 цифре числа через пробнел) :" << '\n';
    std::cout << "например как в 16-ой системе ввесте 41: это будет выглядеть так: 178 = B 2" << '\n';
    std::string num1;
    int count1 = 0, sign1 = 0;
    int check1 = 0;
    for (;;) {
      check1 = 0;
      std::getline(std::cin, num1);
      while (count1 < num1.length()) {
        if ((isalnum(num1[count1]) != 1) && (num1[count1] < 'A' || num1[count1] > 'F') && num1[count1] != ' ' && num1[0] != '-') {
          num1.clear();
          count1 = 0;
          check1 = 1;
          std::cout <<"неправильный ввод: " << '\n';
          break;
        }
        else if ((num1[count1] == ' ' && num1[count1 + 1] == ' ') || (num1[0] == ' ' || num1[num1.length() - 1] == ' ')) {
          num1.clear();
          count1 = 0;
          check1 = 1;
          std::cout <<"неправильный ввод: " << '\n';
          break;
        }
        ++count1;
      }
      if (check1 != 1) {
        break;
      }
    }
    if (num1[0] == '-') {
      sign1 = 1;
      num1.erase(0, 1);
    }  
    else {
      sign1 = 0;
    }
    int size1 = SizeofNum(num1);
    
    std::cout << "введите второе число, в той системе счисления, которую вы задали(ввод осуществлять по 1 цифре числа через пробнел) :" << '\n';
    std::string num2;
    int count2 = 0, sign2 = 0;
    int check2 = 0;
    for (;;) {
      check2 = 0;
      std::getline(std::cin, num2);
      while (count2 < num2.length()) {
        if ((isalnum(num2[count2]) != 1) && (num2[count2] < 'A' || num2[count2] > 'F') && (num2[count2] != ' ') && (num2[0] != '-')) {
          num2.clear();
          count2 = 0;
          check2 = 1;
          std::cout <<"неправильный ввод: " << '\n';
          break;
        }
        else if ((num2[count2] == ' ' && num2[count2 + 1] == ' ') || num2[0] == ' ' || num2[num2.length() - 1] == ' ') {
          num2.clear();
          count2 = 0;
          check2 = 1;
          std::cout <<"неправильный ввод: " << '\n';
          break;
        }
        ++count2;
      }
      if (check2 != 1) {
        break;
      }
    }
    if (num2[0] == '-') {
      sign2 = 1;
      num2.erase(0, 1);
    }  
    else {
      sign2 = 0;
    }
    int size2 = SizeofNum(num2);
    if (size1 > size2) {
      for (int i = 0; i < size1 - size2; ++i) {
        num2.insert(0, "0 ");
      }
    }
    else if (size2 > size1) {
      for (int i = 0; i < size2 - size1; ++i) {
        num1.insert(0, "0 ");
      }
    }
    size1 = SizeofNum(num1);
    size2 = SizeofNum(num2);
    std::string* number1 = new std::string[size1];
    Transformation(num1,number1);
    std::string* number2 = new std::string[size2];
    Transformation(num2,number2);
    std::string** matrix = new std::string*[2];
    for (int i = 0; i < 2; ++i) {
      matrix[i] = new std::string[notation];
    }
    Matrix(matrix,notation);
    if ((InputCheck (matrix, number1, notation, size1) == false) || (InputCheck (matrix, number2, notation, size2) == false)) {
      std::cout << "числа что вы ввели не существуют в заданной вами системе счисления - попытайте удачу заново: " << '\n' << '\n';
      for (int i = 0; i < 2; ++i) {
        delete[] matrix[i];
        matrix[i] = nullptr;
      }
      delete[] matrix;
      matrix = nullptr;
      delete[] number1;
      number1 = nullptr;
      delete[] number2;
      number2 = nullptr;
      goto start;
    }
    //до этого момента работала проверка на ввод теперь основная часть программы
    std::string *Sum = new std::string[size1 + 1];
    std::string *rasnost = new std::string[size1 + 1];
    //разные случаи чтобы правильно использовать вычитание 
    if (Compare(matrix, number1, number2,notation,size1) == 0 && (sign1 == 0 && sign2 == 0)) { // если оба числа равны по модулю
      std::cout << "Sum = +";
      Summary (matrix, number1, number2, Sum, notation, size1);
      std::cout << "Raznost = +";
      Raznost(matrix, number1, number2,  rasnost, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 0 && (sign1 == 1 && sign2 == 1)) {
      std::cout << "Sum = -";
      Summary (matrix, number1, number2, Sum, notation, size1);
      std::cout << "Raznost = +";
      Raznost(matrix, number1, number2,  rasnost, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 0 && (sign1 == 1 && sign2 == 0)) {
      std::cout << "Sum = -";
      Raznost (matrix, number1, number2, Sum, notation, size1);
      std::cout << "Raznost = -";
      Summary(matrix, number1, number2,  rasnost, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 0 && (sign1 == 0 && sign2 == 1)) {
      std::cout << "Sum = -";
      Raznost (matrix, number1, number2, Sum, notation, size1);
      std::cout << "Raznost = +";
      Summary(matrix, number1, number2,  rasnost, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 1 && sign1 == 0 && sign2 == 0) { // если первое бошьше вторго и оба числа положительные
      std::cout << "Sum = +";
      Summary (matrix, number1, number2, Sum, notation, size1);
      std::cout << "Raznost = +";
      Raznost(matrix, number1, number2,  rasnost, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 1 && sign1 == 1 && sign2 == 1) { //если первое больше второго и оба числа отрицательные
      std::cout << "Sum = -";
      Summary(matrix, number1, number2,  rasnost, notation, size1);
      std::cout << "Raznost = -";
      Raznost (matrix, number1, number2, Sum, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 1 && sign1 == 1 && sign2 == 0) { //если первое больше второго и первое отрицательное а второе положительное
      std::cout << "Sum = -";
      Raznost(matrix, number1, number2,  rasnost, notation, size1);
      std::cout << "Raznost = -";
      Summary (matrix, number1, number2, Sum, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 1 && sign1 == 0 && sign2 == 1) { //если первое больше второго и первое положительное а второе отрицательное
      std::cout << "Sum = +";
      Raznost(matrix, number1, number2,  rasnost, notation, size1);
      std::cout << "Raznost = +";
      Summary (matrix, number1, number2, Sum, notation, size1);
    }
    // теперь если второе больше первого
    else if (Compare(matrix, number1, number2,notation,size1) == 2 && sign1 == 0 && sign2 == 0) { // если второе бошьше первого и оба числа положительные
      std::cout << "Sum = +";
      Summary (matrix, number1, number2, Sum, notation, size1);
      std::cout << "Raznost = -";
      Raznost(matrix, number2, number1,  rasnost, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 2 && sign1 == 1 && sign2 == 1) { //если второе больше первого и оба числа отрицательные
      std::cout << "Sum = -";
      Summary(matrix, number1, number2,  rasnost, notation, size1);
      std::cout << "Raznost = +";
      Raznost (matrix, number2, number1, Sum, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 2 && sign1 == 1 && sign2 == 0) { //если второе больше первого и первое отрицательное а второе положительное
      std::cout << "Sum = +";
      Raznost(matrix, number2, number1,  rasnost, notation, size1);
      std::cout << "Raznost = -";
      Summary (matrix, number1, number2, Sum, notation, size1);
    }
    else if (Compare(matrix, number1, number2,notation,size1) == 2 && sign1 == 0 && sign2 == 1) { //если второе больше первого и первое положительное а второе отрицательное
      std::cout << "Sum = -";
      Raznost(matrix, number2, number1,  rasnost, notation, size1);
      std::cout << "Raznost = +";
      Summary (matrix, number1, number2, Sum, notation, size1);
    }
    else {
      std::cout << "eto chto esho takoe?" << '\n';
    }


    for (int i = 0; i < 2; ++i) {
      delete[] matrix[i];
      matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    delete[] number1;
    number1 = nullptr;
    delete[] number2;
    number2 = nullptr;
    delete[] Sum;
    Sum = nullptr;
    delete[] rasnost;
    rasnost = nullptr;
    return 0;
  }
  else if (Task == 4) {
    getchar();
    std::cout << "введите число, которое хочете проверить на кратность 7, 29 и 149: " << '\n';
    std::string number;
    std::string time;
    int count = 0, check = 0;
    for (;;) {
      check = 0;
      std::getline(std::cin, number);
      while (count < number.length()) {
        if (isdigit(number[count]) != 1 || number[0] == '0') {
          number.clear();
          count = 0;
          check = 1;
          std::cout <<"неправильный ввод: " << '\n';
          break;
        }
        ++count;
      }
      if (check != 1) {
        break;
      }
    }
    Kratnost29(number, number.length());
    Kratnost7(number, number.length());
    Kratnost149(number, number.length());
    return 0; 
  }
  else if (Task == 5) {
    int* barrels = new int[240];
    for (int i = 0; i < 240; ++i) {
      barrels[i] = 0;
    }
    std::cout << "введите номер бочки(1-240) которую отравил штирлиц: " << '\n';
    int poison = 0;
    while (!(std::cin >> poison) || (std::cin.peek() != '\n') || poison < 1 || poison > 240) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "неправильный ввод(1-240):  " << std::endl;
    }
    --poison;//для правильного размещения в массиве
    for (int i = 0; i < 240; ++i) {
      if(i == poison) {
        barrels[i] = 1;
        break;
      }
    }
    std::cout << "отравленная бочка находится под номером: " << FindPoison(barrels);
    return 0;
  }
}


void OurArr(int* arr, int count) {
  for (int i = 0; i < count; ++i) {
    std::cout << arr[i];
  }
  std::cout << '\n';
}
void IntoReverseCode (int* arr, int count) {
  if (arr[0] == 1) {
    for (int i = 1; i < count; ++i) {
      if (arr[i] == 0) {
        arr[i] = 1;
      }
      else {
        arr[i] = 0;
      }
    }
  }
}

void Inicialization (int* number, int count ,std::string str) {
  for (int i = 0; i < count; ++i) {
    number[i] = (int)str[i] - 48;
  }
}

void IntoNumArr (int* number_Reverse, int count ,std::string res) {
  int b = 0;
  for (int i = 0; i < count; ++i) {
    b = res[i] - 48;
    number_Reverse[i] = b;
  }
}

int Delenie (int* number, std::string& res1, int count) {
  int counter = 0, stringCounter = 0, check = 0;
  for (;;) {
    counter = 0;
    check = 0;
    while (counter < count) {
      if (number[counter] != 0) {
        check = 1;
        break;
      }
      ++counter;
    }
    if (check == 0) {
      return stringCounter;
    }
    while (counter < count) {
      if (counter < count - 1) {
        number[counter + 1] += 10 * (number[counter] % 2);
        number[counter] = number[counter] / 2;
      }
      else {
        res1 += (number[counter] % 2) + '0';
        number[counter] = number[counter] / 2;
        ++stringCounter;
      }
      ++counter;
    }
  }
}
void SumInReverse(int* number1_Reverse,int* number2_Reverse,int count) {
  int check, check2;
  for (int i = count - 1; i >= 0; --i) {
    if (i == 0) {
      int finish = number1_Reverse[i] + number2_Reverse[i];
      number1_Reverse[i] = (number1_Reverse[i] + number2_Reverse[i]) % 2;
      if (finish >= 2) {
        number1_Reverse[count - 1] += 1;
        for (int i = count - 1; i >= 0; --i) {
          if (number1_Reverse[i] >= 2) {
            number1_Reverse[i - 1] += 1;
            number1_Reverse[i] = 0;
          }
          else {
            number1_Reverse[i] = 1;
            break;
          }
          if (i == 2) {
            break;
          }
        }
      }
    }
    else {
      number1_Reverse[i] += number2_Reverse[i];
      check2 = number1_Reverse[i];
      if (number1_Reverse[i] >= 2) {
        number1_Reverse[i-1] += 1;
      }
        check = number1_Reverse[i] % 2;
        number1_Reverse[i] = number1_Reverse[i] % 2;
    }
  }
}
void TransformIntoAdditionalCode (int* arr, int count) {
  if (arr[0] == 1) {
    if (arr[count - 1] == 0) {
      arr[count - 1] = 1;
    }
    else {
      arr[count - 1] = 0;
      for (int i = count - 1; i >= 2; --i) {
        if (arr[i - 1] == 0) {
          arr[i - 1] = 1;
          break;
        }
        else {
          arr[i - 1] = 0;
        }
      }
    }
  }
}
void IntoReverseCode (std::string& str) {
  if (str[0] == '1') {
    for (int i = 1; i < str.length(); ++i) {
      if (str[i] == '0') {
        str[i] = '1';
      }
      else {
        str[i] = '0';
      }
    }
  }
}

double Calculations (std::string str) {
  int Extent = 0;
  long double Sum = 0;
  for (int i = str.length() - 1; i != 0; --i) {
    if (str[i] == '1') {
      Sum += pow(2, Extent);
    }
    Extent++;
  }
  return Sum;
}
int SizeofNum(std::string num) {
  int count = 1;
  for (int i = 0;i < num.length(); ++i) {
    if (num[i] == ' ') {
      ++count;
    }
  }
  return count;
}
void Transformation(std::string num, std::string* number) {
  int count = 0;
  std::string currentNumber;
  for (int i = 0; i < num.length(); ++i) {
    if (num[i] != ' ') {
      currentNumber += num[i];
    } else {
      if (!currentNumber.empty()) {
        number[count] = currentNumber;
        ++count;
        currentNumber.clear();
      }
    }
  }
  if (!currentNumber.empty()) {
    number[count] = currentNumber;
    ++count;
  }
}
void Matrix(std::string** matrix, long long notation) {
  for (int i = 0; i < 10; ++i) {
    matrix[0][i] = std::to_string(i);
    matrix[1][i] = std::to_string(i);
  }
  for (long long i = 0; i < notation - 10; ++i) {
    std::string result;
    long long num = i;

    while (num >= 0) {
      result = static_cast<char>('A' + (num % 26)) + result;
      num = num / 26 - 1;
    }
    
    matrix[0][i+10] = result;
    matrix[1][i+10] = std::to_string(i+10);
  }
}
bool InputCheck (std::string** matrix, std::string*number, long long notation, int size) {
  int numbersCount = 0;
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < notation; ++j) {
      if (matrix[0][j] == number[i]) {
        ++numbersCount;
      }
    }
  }
  if (numbersCount < size) {
    return false;
  }
  else {
    return true;
  }
}
void Summary(std::string** matrix, std::string* number1, std::string* number2, std::string* Sum, long long notation, int size) {
  int num1 = 0, num2 = 0, sum = 0, ostatok = 0, check1 = 0, check2 = 0;
  std::string summa;
  for (int i = (size - 1); i >= 0; --i) {
    check1 = 0;
    check2 = 0;
    for (int j = 0; j < notation; ++j) {
      if (number1[i] == matrix[0][j]) {
        num1 = std::stoi(matrix[1][j]);
        check1 = 1;
      }
      if (number2[i] == matrix[0][j]) {
        num2 = std::stoi(matrix[1][j]);
        check2 = 1;
      }
      if (check1 == 1 && check2 == 1) {
        sum = num1 + num2 + ostatok;
        if (sum < notation) {
          ostatok = 0;
          summa = std::to_string(sum);
          for (int l = 0; l < notation; ++l) {
            if (summa == matrix[1][l]) {
              Sum[i + 1] = matrix[0][l];
              break;
            }
          }
        }
        else {
          ostatok = 1;
          sum %= notation;
          summa = std::to_string(sum);
          for (int l = 0; l < notation; ++l) {
            if (summa == matrix[1][l]) {
              Sum[i + 1] = matrix[0][l];
              break;
            }
          }
        }
        if (i == 0) {
          sum = ostatok;
          summa = std::to_string(sum);
          for (int l = 0; l < notation; ++l) {
            if (summa == matrix[1][l]) {
              Sum[i] = matrix[0][l];
              break;
            }
          }
        }
        break;
      }
    }
  }
  for (int i = 0; i <= size; ++i) {
    std::cout << Sum[i] << ' ';
  }
  std::cout << '\n';
}
//вычитание из большего меньшее
void Raznost(std::string** matrix, std::string* number1, std::string* number2, std::string* rasnost, long long notation, int size) { 
  int num1 = 0, num2 = 0, razn = 0, ostatok = 0, check1 = 0, check2 = 0;
  std::string raznostString;
  for (int i = (size - 1); i >= 0; --i) {
    check1 = 0;
    check2 = 0;
    for (int j = 0; j < notation; ++j) {
      if (number1[i] == matrix[0][j]) {
        num1 = std::stoi(matrix[1][j]);
        check1 = 1;
      }
      if (number2[i] == matrix[0][j]) {
        num2 = std::stoi(matrix[1][j]);
        check2 = 1;
      }
      razn = num1 - num2 - ostatok;
      if ((check1 == 1 && check2 == 1) && (razn >= 0)) {
        ostatok = 0;
        raznostString = std::to_string(razn);
        for (int l = 0; l < notation; ++l) {
          if (raznostString == matrix[1][l]) {
            rasnost[i] = matrix[0][l];
            break;
          }
        }
      }
      else if ((check1 == 1 && check2 == 1) && (razn < 0)) {
        ostatok = 1;
        razn += notation;
        raznostString = std::to_string(razn);
        for (int l = 0; l < notation; ++l) {
          if (raznostString == matrix[1][l]) {
            rasnost[i] = matrix[0][l];
            break;
          }
        }
      }
      if (check1 == 1 && check2 == 1) {
        break;
      }
    }
  }
  for (int i = 0; i < size; ++i) {
    std::cout << rasnost[i] << ' ';
  }
  std::cout << '\n';
}
int Compare(std::string** matrix, std::string* number1, std::string* number2, long long notation, int size) {
  long long j1 = 0, j2 = 0;
  int check1 = 0, check2 = 0;
  for (int i = 0; i < size; ++i) {
    check1 = 0;
    check2 = 0;
    for (int j = 0; j < notation; ++j) {
      if (number1[i] == matrix[0][j]) {
        j1 = j;
        check1 = 1;
      }
      if (number2[i] == matrix[0][j]) {
        j2 = j;
        check2 = 1;
      }
      if (((check1 == 1) && (check2 == 1)) && (j1 > j2)) {
        return 1;
      }
      else if (((check1 == 1) && (check2 == 1)) && (j1 < j2)) {
        return 2;
      }
      else if ((((check1 == 1) && (check2 == 1)) && (j1 == j2))) {
        break;
      }
    }
  }
  return 0;
}
void Kratnost29(std::string& number , int length) {
  int index = 3; // коэфицент для проверки
  int pribavka = 0, check = 0, desyatki = 0, edinici = 0, time = 0, new_lens = 0, last = 0, answer = 0; 
  std::string time_string;
  std::string time_number;
  std::string novoe_chislo;

  novoe_chislo = number;


  for (int j = 0; j < 1000000 ; ++j) {
    length = novoe_chislo.length();
    if (length <= 2) {
      int a = std::stoi(novoe_chislo);
      check = 29;
      while (check < 100) {
        if (check == a) {
          answer = 1;
        }
        check += 29;
      }
      if (answer == 1) {
        std::cout << "число делиться на 29" << '\n';
        break;
      }
      else {
        std::cout << "число не делиться на 29" << '\n';
        break;
      }
    }
    int* arr = new int[length];
    arr[0] = 0;
    for (int i = 1; i < length; ++i) { 
      time_string = novoe_chislo[i - 1];
      arr[i] = std::stoi(time_string); 
    }
    check = 0;
    time_string = novoe_chislo[novoe_chislo.length() - 1];
    last = std::stoi(time_string);
    while (check < last) {
      pribavka += index;
      ++check;
    }
    check = 0;
    time_string = std::to_string(pribavka);
    time_number = time_string[time_string.length() - 1];
    edinici = std::stoi(time_number);
    if (pribavka >= 10) {
      time_string = std::to_string(pribavka);
      time_number = time_string[time_string.length() - 2];
      desyatki = std::stoi(time_number);
    }
    pribavka = 0;
    arr[length-1] += edinici;
    arr[length-2] += desyatki;

    for (int i = length - 1; i >= 1; --i) {
      if (arr[i] >= 10) {
        time_string = std::to_string(arr[i]);
        time_number = time_string[1];
        arr[i] = std::stoi(time_number);
        ++arr[i - 1];
      }
    }
    if (arr[0] == 0) {
      new_lens = length - 1;
    }
    else {
      new_lens = length;
    }
    novoe_chislo.clear();
    for (int i = length - new_lens; i < length; ++i) {
      novoe_chislo += std::to_string(arr[i]);
    } 
    //std::cout << novoe_chislo << '\n';
    delete[] arr;
    arr = nullptr; 
    time_string.clear();
    time_number.clear();
    desyatki = 0;
    edinici = 0;
    time = 0;
    new_lens = 0;
    last = 0;
  }
}

void Kratnost7(std::string& number , int length) {
  int index = 5; // коэфицент для проверки
  int pribavka = 0, check = 0, desyatki = 0, edinici = 0, time = 0, new_lens = 0, last = 0, answer = 0; 
  std::string time_string;
  std::string time_number;
  std::string novoe_chislo;

  novoe_chislo = number;


  for (int j = 0; j < 1000000 ; ++j) {
    length = novoe_chislo.length();
    if (length <= 2) {
      int a = std::stoi(novoe_chislo);
      check = 7;
      while (check < 100) {
        if (check == a) {
          answer = 1;
        }
        check += 7;
      }
      if (answer == 1) {
        std::cout << "число делиться на 7" << '\n';
        break;
      }
      else {
        std::cout << "число не делиться на 7" << '\n';
        break;
      }
    }
    int* arr = new int[length];
    arr[0] = 0;
    for (int i = 1; i < length; ++i) { 
      time_string = novoe_chislo[i - 1];
      arr[i] = std::stoi(time_string); 
    }
    check = 0;
    time_string = novoe_chislo[novoe_chislo.length() - 1];
    last = std::stoi(time_string);
    while (check < last) {
      pribavka += index;
      ++check;
    }
    check = 0;
    time_string = std::to_string(pribavka);
    time_number = time_string[time_string.length() - 1];
    edinici = std::stoi(time_number);
    if (pribavka >= 10) {
      time_string = std::to_string(pribavka);
      time_number = time_string[time_string.length() - 2];
      desyatki = std::stoi(time_number);
    }
    pribavka = 0;
    arr[length-1] += edinici;
    arr[length-2] += desyatki;

    for (int i = length - 1; i >= 1; --i) {
      if (arr[i] >= 10) {
        time_string = std::to_string(arr[i]);
        time_number = time_string[1];
        arr[i] = std::stoi(time_number);
        ++arr[i - 1];
      }
    }
    if (arr[0] == 0) {
      new_lens = length - 1;
    }
    else {
      new_lens = length;
    }
    
    novoe_chislo.clear();
    for (int i = length - new_lens; i < length; ++i) {
      novoe_chislo += std::to_string(arr[i]);
    } 
    //std::cout << novoe_chislo << '\n';
    delete[] arr;
    arr = nullptr; 
    time_string.clear();
    time_number.clear();
    desyatki = 0;
    edinici = 0;
    time = 0;
    new_lens = 0;
    last = 0;
  }
}
void Kratnost149(std::string& number , int length) {
  int index = 15; // коэфицент для проверки
  int pribavka = 0, check = 0, desyatki = 0, edinici = 0, time = 0, new_lens = 0, last = 0, answer = 0, sotka = 0; 
  std::string time_string;
  std::string time_number;
  std::string novoe_chislo;

  novoe_chislo = number;


  for (int j = 0; j < 1000000 ; ++j) {
    length = novoe_chislo.length();
    if (length <= 3) {
      int a = std::stoi(novoe_chislo);
      check = 149;
      while (check < 1000) {
        if (check == a) {
          answer = 1;
        }
        check += 149;
      }
      if (answer == 1) {
        std::cout << "число делиться на 149" << '\n';
        break;
      }
      else {
        std::cout << "число не делиться на 149" << '\n';
        break;
      }
    }
    int* arr = new int[length];
    arr[0] = 0;
    for (int i = 1; i < length; ++i) { 
      time_string = novoe_chislo[i - 1];
      arr[i] = std::stoi(time_string); 
    }
    check = 0;
    time_string = novoe_chislo[novoe_chislo.length() - 1];
    last = std::stoi(time_string);
    while (check < last) {
      pribavka += index;
      ++check;
    }
    check = 0;
    time_string = std::to_string(pribavka);
    time_number = time_string[time_string.length() - 1];
    edinici = std::stoi(time_number);
    if (pribavka >= 10) {
      time_string = std::to_string(pribavka);
      time_number = time_string[time_string.length() - 2];
      desyatki = std::stoi(time_number);
    }
    if (pribavka >= 100) {
      time_string = std::to_string(pribavka);
      time_number = time_string[time_string.length() - 3];
      sotka = std::stoi(time_number);
    }
    pribavka = 0;
    arr[length-1] += edinici;
    arr[length-2] += desyatki;
    arr[length-3] += sotka;

    for (int i = length - 1; i >= 1; --i) {
      if (arr[i] >= 10) {
        time_string = std::to_string(arr[i]);
        time_number = time_string[1];
        arr[i] = std::stoi(time_number);
        ++arr[i - 1];
      }
    }
    if (arr[0] == 0) {
      new_lens = length - 1;
    }
    else {
      new_lens = length;
    }
    
    novoe_chislo.clear();
    for (int i = length - new_lens; i < length; ++i) {
      novoe_chislo += std::to_string(arr[i]);
    } 
    //std::cout << novoe_chislo << '\n';
    delete[] arr;
    arr = nullptr; 
    time_string.clear();
    time_number.clear();
    desyatki = 0;
    edinici = 0;
    time = 0;
    new_lens = 0;
    last = 0;
  }
}
int FindPoison (int* barrels) {
    int check = -1, right_limit = 0, left_limit = 0, dead = 0;
    bool rab1 = true, rab2 = true, rab3 = true, rab4 = true, rab5 = true;
    for (int i = 0; i < 240; ++i) {
      if (barrels[i] == 1) {
        check = i;
      }
      if (check >= 0 && check < 80) { // 1 умрет
        if (check < 16) {
          rab1 = false;
          left_limit = 0;
          right_limit = 15;
        }
        else if (check < 32) {
          rab2 = false;
          left_limit = 16;
          right_limit = 31;
        }
        else if (check < 48) {
          rab3 = false;
          left_limit = 32;
          right_limit = 47;
        }
        else if (check < 64) {
          rab4 = false;
          left_limit = 48;
          right_limit = 63;
        } 
        else {
          rab5 = false;
          left_limit = 64;
          right_limit = 79;
        }
      }
      else if (check >= 80 && check < 160) { // 2 умрет
        if (check < 88) {
          rab1 = false;
          rab2 = false;
          left_limit = 80;
          right_limit = 87;
        }
        else if (check < 96) {
          rab1 = false;
          rab3 = false;
          left_limit = 88;
          right_limit = 95;
        }
        else if (check < 104) {
          rab1 = false;
          rab4 = false;
          left_limit = 96;
          right_limit = 103;
        }
        else if (check < 112) {
          rab1 = false;
          rab5 = false;
          left_limit = 104;
          right_limit = 111;
        }
        else if (check < 120) {
          rab2 = false;
          rab3 = false;
          left_limit = 112;
          right_limit = 119;
        }
        else if (check < 128) {
          rab2 = false;
          rab4 = false;
          left_limit = 120;
          right_limit = 127;
        }
        else if (check < 136) {
          rab2 = false;
          rab5 = false;
          left_limit = 128;
          right_limit = 135;
        }
        else if (check < 144) {
          rab3 = false;
          rab4 = false;
          left_limit = 136;
          right_limit = 143;
        }
        else if (check < 152) {
          rab3 = false;
          rab5 = false;
          left_limit = 144;
          right_limit = 151;
        }
        else if (check < 160) {
          rab4 = false;
          rab5 = false;
          left_limit = 152;
          right_limit = 159;
        }
      }
      else if (check >= 160 && check < 200) { // 3 умрет
        if (check < 164) {
          rab1 = false;
          rab2 = false;
          rab3 = false;
          left_limit = 160;
          right_limit = 163;
        }
        else if (check < 168) {
          rab1 = false;
          rab2 = false;
          rab4 = false;
          left_limit = 164;
          right_limit = 167;
        }
        else if (check < 172) {
          rab1 = false;
          rab2 = false;
          rab5 = false;
          left_limit = 168;
          right_limit = 171;
        }
        else if (check < 176) {
          rab1 = false;
          rab3 = false;
          rab4 = false;
          left_limit = 172;
          right_limit = 175;
        }
        else if (check < 180) {
          rab1 = false;
          rab3 = false;
          rab5 = false;
          left_limit = 176;
          right_limit = 179;
        }
        else if (check < 184) {
          rab1 = false;
          rab4 = false;
          rab5 = false;
          left_limit = 180;
          right_limit = 183;
        }
        else if (check < 188) {
          rab2 = false;
          rab3 = false;
          rab4 = false;
          left_limit = 184;
          right_limit = 187;
        }
        else if (check < 192) {
          rab2 = false;
          rab3 = false;
          rab5 = false;
          left_limit = 188;
          right_limit = 191;
        }
        else if (check < 196) {
          rab2 = false;
          rab4 = false;
          rab5 = false;
          left_limit = 192;
          right_limit = 195;
        }
        else if (check < 200) {
          rab3 = false;
          rab4 = false;
          rab5 = false;
          left_limit = 196;
          right_limit = 199;
        }
      }
      else if (check >= 200 && check < 210) { // 4 умрет
        if (check < 202) {
          rab1 = false;
          rab2 = false;
          rab3 = false;
          rab4 = false;
          left_limit = 200;
          right_limit = 201;
        }
        else if (check < 204) {
          rab1 = false;
          rab2 = false;
          rab3 = false;
          rab5 = false;
          left_limit = 202;
          right_limit = 203;
        }
        else if (check < 206) {
          rab1 = false;
          rab2 = false;
          rab4 = false;
          rab5 = false;
          left_limit = 204;
          right_limit = 205;
        }
        else if (check < 208) {
          rab1 = false;
          rab3 = false;
          rab4 = false;
          rab5 = false;
          left_limit = 206;
          right_limit = 207;
        }
        else if (check < 210) {
          rab2 = false;
          rab3 = false;
          rab4 = false;
          rab5 = false;
          left_limit = 208;
          right_limit = 209;
        }
      }
      else {// если не выполнилось ни 1 из передних условий -> осталось живо 5 рабов и на них 30 банок
        left_limit = 210;
        right_limit = 239;
      }
      if (rab1 == false) {
        ++dead;
      }
      if (rab2 == false) {
        ++dead;
      }
      if (rab3 == false) {
        ++dead;
      }
      if (rab4 == false) {
        ++dead;
      }
      if (rab5 == false) {
        ++dead;
      }
      if (check != -1) {
        break;
      }
    }
    int position = check - left_limit;
    int survive = 5 - dead;
    int** matrix = new int*[pow(2,survive)];
    for (int i = 0; i < pow(2,survive); ++i) {
      matrix[i] = new int[survive];
    }

    for (int i = 0; i < pow(2,survive); ++i) {
      for (int j = survive-1 ; j >=0; --j) {
      int value = (i >> j) & 1;
      matrix[i][j] = value;
      }
    }
    int stepen = 0, Sum = 0;
    for (int i = 0; i < pow(2,survive); ++i) {
      if (i == position) {
        for (int j = 0; j <= survive-1; ++j) {
          Sum += (matrix[i][j] * pow(2,stepen));
          //std::cout << "Sum= "<< Sum << ' ' << "matrix= " << matrix[i][j];
          ++stepen;
        }
        break;
      }
    }
    Sum = Sum + left_limit + 1;


    for (int i = 0; i < pow(2,survive); ++i) {
      delete[] matrix[i];
      matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    return Sum;
  }

