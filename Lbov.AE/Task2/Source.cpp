#include "Header.h"

ostream& operator<<(std::ostream& out,  Vector& s) {
    
    ifstream input;
    Vector m1;
    input.open("C:\\Users\\aleks\\IiP_381908_2_2\\Lbov.AE\\Task2\\in.txt");
    if (!input) {
        cout << "Такой файл не был найден";
        exit(0);
    }
    else {

        int number;

        while (!input.eof())
        {
            input >> number;
            s.n++;
        }
        input.close();
       

        s.v = new int[s.n];

        input.open("C:\\Users\\aleks\\IiP_381908_2_2\\Lbov.AE\\Task2\\in.txt");
        for (int i = 1; i <= s.n; i++) {
            input >> s.v[i];
            out << s.v[i] << endl;

        }
        out <<endl<< s.n<<endl;
        cout << "===================Данные считаны======================" << endl;

        input.close();

        
    }
    return out;
}
 istream& operator>>(istream& in, Vector& s) {
     ofstream output;
     output.open("C:\\Users\\aleks\\IiP_381908_2_2\\Lbov.AE\\Task2\\out.txt", ios::trunc);
     if (!output) {
         cout << "Такой файл не был найден";
         exit(0);
     }
     else {
         for (int i = 1; i <= s.n; i++)
             output << s.v[i]<<" ";
        
     }
 }

int& Vector::operator[] (const unsigned int index){
    
    if (index > n) {
        cout << "такого вектора не существует";
        
    }
    else {
        cout << "кол-во ячеек " << n << " " << index;
        return(v[index]);
    }
}
Vector operator+(  Vector& vec , const Vector &vec1) {
    
    if ((vec.n < vec.x * 4) || (vec.n < vec1.x1 * 4))
    {
        cout << "Данного вектора не существует"; 
        exit(0);
    }
    else {
        cout<<" Сумма векторов "<< vec.v[vec.x * 4 - 3] + vec.v[vec.x1 * 4 - 3]<<" "<< vec.v[vec.x * 4 -2] + vec.v[vec.x1 * 4 -2] << " " << vec.v[vec.x * 4 - 1] + vec.v[vec.x1 * 4 - 1] << " " << vec.v[vec.x * 4 ] + vec.v[vec.x1 * 4 ] ;
        return vec;
    }
    }
Vector operator*( Vector& vec, const Vector& vec1) {
    if ((vec.n < vec.x * 4) || (vec.n < vec1.x1 * 4))
    {
        cout << "Данного вектора не существует";
        exit(0);
    }
    else {
     
        cout << vec.v[vec.x * 4 - 3] * vec.v[vec.x1 * 4 - 3] + vec.v[vec.x * 4 - 2] * vec.v[vec.x1 * 4 - 2] + vec.v[vec.x * 4 - 1] * vec.v[vec.x1 * 4 - 1] +vec.v[vec.x * 4 ] * vec.v[vec.x1 * 4] ;

        return vec;
    }
    
}
Vector operator*=(Vector& vec, const Vector& vec1) {
    if (vec.n < vec.x * 4) {
        cout << "Данного вектора не существует";
        exit(0);
    }
    else {
        cout << vec.v[vec.x * 4 -3] * vec.x1 << " " << vec.v[vec.x * 4-2] * vec.x1<<" "<< vec.v[vec.x * 4 - 1] * vec.x1<<" "<< vec.v[vec.x * 4 ] * vec.x1;
        return vec;
    }
}
Vector& Vector::operator=(Vector& vec) {
    if (vec.n < vec.x * 4) {
        cout << "Данного вектора не существует";
        exit(0);
    }
    else {
        v[vec.x * 4 - 3] = x1;
        v[vec.x * 4 - 2] = x1;
        v[vec.x * 4 - 1] = x1;
        v[vec.x * 4] = x1;
        cout << " Новое значение вектора " << v[vec.x * 4 - 3] << " " << v[vec.x * 4 - 2] << " " << v[vec.x * 4 - 1] << " " << v[vec.x * 4];
        return vec;
    }
}
