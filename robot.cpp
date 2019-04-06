/*У вас есть робот, который умеет взбираться вверх по лестнице с конечным количеством ступеней. 
Для этого вам предоставляется низкоуровневая функцию , которая заставляет робота попытаться взобраться на 1 ступень step() вверх. 
К сожалению, иногда у робота это не получается, и он вместо того чтобы взобраться на 1 ступень вверх, падает и опускается 
на 1 ступень вниз от исходного положения (если ему есть куда опускаться). Робот определяет успешность выполнения операции,
и результат вам возвращается в качестве результата функции : 1 - успешно; 0 - не step() успешно (падение).
Требуется написать функцию , которая приводит к тому, что робот поднимается ровно на 1 ступень вверх. - stepUp(N) N номер ступени,
на которой находится робот в настоящий момент. Ступени нумеруются снизу вверх, начиная с единицы*/

#include <iostream>

using namespace std;

int N;                                      //позиция робота, вводимая пользователем
int temp, res, st_pos;                      //временные переменные для хранения данных(temp,res) и st_pos для контроля позиции робота
int step();
void stepUp(int N);
int rand_m[10] = {0, 1, 1, 0, 1, 0, 0, 1, 0, 1}; //массив значений от 0 до 1 для рандомного выбора значения получаемого функцией step()

int main()
{
    cout<<"Введите N:" << endl;
    cin >> N;
    stepUp(N);
    return 0;
}

/*Из-за того, что функция (rand % 2) является условно рандомной и всегда возвращает
одинаковые значения (первым из которых является 1, т.е. робот всегда успешно поднимался 
на одну ступеньку с первой попытки) было решено реализовать свой псевдо рандомный 
способ выполнения функции step(), а именно выбор функцией rand() числового значения от 0 до 9
и последующий выбор элемента массива с соответствующим индексом (значения элементов массива
это 0 и 1). Таким образом изменяя начальную позицию робота и меняя местами элементы массива
можно рассмотреть действительно разные ситуации действия робота.*/

int step(){
    temp = rand() % 10;
    if(rand_m[temp] == 1){
        return 1;
    }
    else {
        return 0;
    }
    
}

void stepUp(int N){
    st_pos = N;
    cout << "The starting position of the robot: " << st_pos << endl;
    while(st_pos <= N){
        res = step();
        if(res == 1){
            st_pos++;
        }
        else{
            if(st_pos >0){
                st_pos--;
            }
        }
        cout << "Time position of the robot at this iteration: " << st_pos << endl;
    }
    cout << "The final position of the robot: " << st_pos << endl;
}
