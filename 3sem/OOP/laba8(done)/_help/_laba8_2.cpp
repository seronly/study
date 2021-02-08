#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void StringtoNumber(string &s, float &f)
{
    char temp[500];
    for (int i = 0; i < (int)s.length(); i++)
        temp[i] = s[i];
    temp[s.length()] = '\0';
    f = (float)atof(temp);
}
void StringtoNumber(string &s, int &i)
{
    char temp[500];
    for (int i = 0; i < (int)s.length(); i++)
        temp[i] = s[i];
    temp[s.length()] = '\0';
    i = atoi(temp);
}

class File
{
protected:
    ofstream Fwrite;
    ifstream Fread;
    string Filename;

public:
    File() { Filename = ""; }
    string getFilename() { return Filename; }
    long getSizeOfFile()
    {
        if (Filename == "")
        {
            cout << "Файл не открыт!" << endl;
            return 0;
        }
        Fread.open(Filename);
        if (Fread)
        {
            long length = 0;
            Fread.seekg(0, ios::end);
            length = Fread.tellg();
            Fread.close();
            return length;
        }
        else
        {
            cout << "Файл не найден!" << endl
                 << "Откройте файл заного!" << endl;
            Filename = "";
            return 0;
        }
    }
    // открыть файл
    void Open(string filename)
    {
        Filename = "";
        Fread.open(filename);
        if (Fread)
        {
            Filename = filename;
            Fread.close();
        }
        else
        {
            cout << "Файла не существует!" << endl
                 << "Создать файл с таким именем?" << endl;
            cout << "1) Да" << endl
                 << "2) Нет" << endl;
            int i;
            do
                cin >> i;
            while (i < 1 || i > 2);
            if (i == 1)
            {
                ofstream ofs(filename);
                ofs.close();
                Filename = filename;
                cout << "Файл создан!" << endl;
            }
        }
    }
    // считать весь файл
    virtual void Read() = 0;
    // новая запись в конец файла
    virtual void Write() = 0;
    // поиск в файле
    virtual void SeeK(string str) = 0;
};

class MyDataFile1 : public File
{
    struct MyData1
    {
        string name;
        float score;
        int age;
        MyData1()
        {
            name = "";
            score = 0;
            age = 0;
        }
        void Write()
        {
            cout << "========================================" << endl;
            cout << name << endl;
            cout << "Возраст " << age << " лет" << endl;
            cout << "Средний балл: " << score << endl
                 << endl;
        }
        void Read(string Name, int Age, float Score)
        {
            name = Name, score = Score;
            age = Age;
        }
    };

public:
    void Read() override
    {
        if (Filename == "")
        {
            cout << "Файл не открыт!" << endl;
            return;
        }
        Fread.open(Filename);
        if (Fread)
        {
            MyData1 temp;
            string str;
            while (getline(Fread, str))
            {
                temp.name = str;
                if (getline(Fread, str))
                    StringtoNumber(str, temp.age);
                else
                    temp.age = 0;
                if (getline(Fread, str))
                    StringtoNumber(str, temp.score);
                else
                    temp.score = 0;
                temp.Write();
            }
            Fread.close();
        }
        else
        {
            cout << "Файл не найден!" << endl
                 << "Откройте файл заного!" << endl;
            Filename = "";
            return;
        }
    }
    void Write() override
    {
        if (Filename == "")
        {
            cout << "Файл не открыт!" << endl;
            return;
        }
        Fwrite.open(Filename, ios::app);
        if (Fwrite)
        {
            MyData1 temp;
            cout << "Введите имя студента: " << endl;
            do
                getline(cin, temp.name);
            while (temp.name == "");
            Fwrite << temp.name << endl;
            cout << "Введите возраст студента: " << endl;
            do
                cin >> temp.age;
            while (temp.age < 18);
            Fwrite << temp.age << endl;
            cout << "Введите средний балл студента: " << endl;
            do
                cin >> temp.score;
            while (temp.score < 0 || temp.score > 5);
            Fwrite << temp.score << endl;
            Fwrite.close();
        }
        else
        {
            cout << "Файл не найден!" << endl
                 << "Откройте файл заного!" << endl;
            Filename = "";
            return;
        }
    }
    void SeeK(string s) override
    {
        if (Filename == "")
        {
            cout << "Файл не открыт!" << endl;
            return;
        }
        Fread.open(Filename);
        if (Fread)
        {
            MyData1 temp;
            string str;
            while (getline(Fread, str))
            {
                if (s == str)
                {
                    temp.name = str;
                    if (getline(Fread, str))
                        StringtoNumber(str, temp.age);
                    else
                        temp.age = 0;
                    if (getline(Fread, str))
                        StringtoNumber(str, temp.score);
                    else
                        temp.score = 0;
                    temp.Write();
                }
                else
                {
                    getline(Fread, str);
                    getline(Fread, str);
                }
            }
            Fread.close();
        }
        else
        {
            cout << "Файл не найден!" << endl
                 << "Откройте файл заного!" << endl;
            Filename = "";
            return;
        }
    }
};

class MyDataFile2 : public File
{
    struct MyData2
    {
        string name;
        float speed;
        void Write()
        {
            cout << "========================================" << endl;
            cout << name << endl;
            cout << "Скорость: " << speed << endl
                 << endl;
        }
        void Read(string Name, float Speed) { name = Name, speed = Speed; }
    };

public:
    void Read() override
    {
        if (Filename == "")
        {
            cout << "Файл не открыт!" << endl;
            return;
        }
        Fread.open(Filename);
        if (Fread)
        {
            MyData2 temp;
            string str;
            while (getline(Fread, str))
            {
                temp.name = str;
                if (getline(Fread, str))
                    StringtoNumber(str, temp.speed);
                else
                    temp.speed = 0;
                temp.Write();
            }
            Fread.close();
        }
        else
        {
            cout << "Файл не найден!" << endl
                 << "Откройте файл заного!" << endl;
            Filename = "";
            return;
        }
    }
    void Write() override
    {
        if (Filename == "")
        {
            cout << "Файл не открыт!" << endl;
            return;
        }
        Fwrite.open(Filename, ios::app);
        if (Fwrite)
        {
            MyData2 temp;
            cout << "Введите марку машины: " << endl;
            do
                getline(cin, temp.name);
            while (temp.name == "");
            Fwrite << temp.name << endl;
            cout << "Введите сорость машины: " << endl;
            do
                cin >> temp.speed;
            while (temp.speed < 0);
            Fwrite << temp.speed << endl;
            Fwrite.close();
        }
        else
        {
            cout << "Файл не найден!" << endl
                 << "Откройте файл заного!" << endl;
            Filename = "";
            return;
        }
    }
    void SeeK(string s) override
    {
        if (Filename == "")
        {
            cout << "Файл не открыт!" << endl;
            return;
        }
        Fread.open(Filename);
        if (Fread)
        {
            MyData2 temp;
            string str;
            while (getline(Fread, str))
            {
                if (s == str)
                {
                    temp.name = str;
                    if (getline(Fread, str))
                        StringtoNumber(str, temp.speed);
                    else
                        temp.speed = 0;
                    temp.Write();
                }
                else
                {
                    getline(Fread, str);
                    getline(Fread, str);
                }
            }
            Fread.close();
        }
        else
        {
            cout << "Файл не найден!" << endl
                 << "Откройте файл заного!" << endl;
            Filename = "";
            return;
        }
    }
};

class Folder
{
    int n;
    File *array[5];

public:
    Folder()
    {
        n = 5;
        array[0] = new MyDataFile1;
        array[1] = new MyDataFile1;
        array[2] = new MyDataFile1;
        array[3] = new MyDataFile2;
        array[4] = new MyDataFile2;
        array[0]->Open("F1.txt");
        array[1]->Open("F2.txt");
        array[2]->Open("F3.txt");
        array[3]->Open("F4.txt");
        array[4]->Open("F5.txt");
    }
    void ReadInfoFail()
    {
        system("cls");
        cout << "Список файлов: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ") ";
            cout << array[i]->getFilename();
            cout << " длина файла: " << array[i]->getSizeOfFile() << endl;
        }
        system("pause");
    }
    void ReadAll()
    {
        system("cls");
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ") " << array[i]->getFilename() << endl;
            array[i]->Read();
        }
        system("pause");
    }
    int setNameFail()
    {
        cout << "Имя файла: " << endl;
        string N;
        int k = -1;
        do
            getline(cin, N);
        while (N == "");
        for (int i = 0; i < n; i++)
            if (N == array[i]->getFilename())
            {
                k = i;
                break;
            }
        if (k == -1)
        {
            cout << "Файл с таким именем не открыт!" << endl;
        }
        return k;
    }
    void NewElem()
    {
        system("cls");
        int N = setNameFail();
        if (N != -1)
            array[N]->Write();
        system("pause");
    }
    void SeekElem()
    {
        system("cls");
        int N = setNameFail();
        string seek;
        cout << "Введите имя: ";
        do
            getline(cin, seek);
        while (seek == "");
        if (N != -1)
            array[N]->SeeK(seek);
        system("pause");
    }
};

int Menu()
{
    int er;
    cout << "1) Вывести информацию о файлах" << endl;
    cout << "2) Вывести данные из всех файлов" << endl;
    cout << "3) Добавть запись в файл" << endl;
    cout << "4) Поиск элемента в файле" << endl;
    cout << "5) Выход" << endl;
    do
        cin >> er;
    while (er < 1 || er > 5);
    return er;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Folder f;
    while (true)
    {
        system("cls");
        switch (Menu())
        {
        case 1:
            f.ReadInfoFail();
            break;
        case 2:
            f.ReadAll();
            break;
        case 3:
            f.NewElem();
            break;
        case 4:
            f.SeekElem();
            break;
        case 5:
            return 0;
            break;
        }
    }
}