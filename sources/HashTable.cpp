#include "HashTable.h"

HashTable::HashTable() {

	for (unsigned int index(0); index < TableSize; ++index) {

		DataBase[index] = nullptr;
	}

	std::cout << "Hash table was successfully created." << std::endl;
}

unsigned int HashTable::Hash(cell* Account) {

    long double coefficient(1), hash(0);

    for (unsigned int index(0); index < Account -> surname.length(); ++index) {

        hash += coefficient * (int)(Account -> surname[index]);
        coefficient /= 2;
    }

    for (unsigned int index(0); index < Account -> name.length(); ++index) {

        hash += coefficient * (int)(Account -> name[index]);
        coefficient *= 2;
    }

    for (unsigned int index(0); index < Account -> patronymic.length(); ++index) {

        hash += coefficient * (int)(Account -> patronymic[index]);
        coefficient /= 2;
    }

    return (int)hash % TableSize;
}

void HashTable::Add(cell* NewCell) {

    int key = Hash(NewCell);

    if(DataBase[key] == nullptr) {

        DataBase[key] = new cell;
//        DataBase[key] = Newcell;

        DataBase[key] -> surname = NewCell -> surname;
        DataBase[key] -> name = NewCell -> name;
        DataBase[key] -> patronymic = NewCell -> patronymic;
        DataBase[key] -> cash = NewCell -> cash;
        DataBase[key] -> next = nullptr;

        /*std::cout << "--------------------------" << std::endl;
                std::cout << "Surname:\t" << NewCell -> surname << std::endl;
                std::cout << "Name:\t\t" << NewCell -> name << std::endl;
                std::cout << "Patronymic:\t" << NewCell -> patronymic << std::endl;
                std::cout << "Cash:\t\t" << NewCell -> cash << std::endl;
                std::cout << "--------------------------" << std::endl;*/

    } else {

        cell* ptr = DataBase[key];

        cell* NewItem = new cell;

        NewItem -> surname = NewCell -> surname;
        NewItem -> name = NewCell -> name;
        NewItem -> patronymic = NewCell -> patronymic;
        NewItem -> cash = NewCell -> cash;
        NewItem -> next = nullptr;

        while (ptr -> next != nullptr) {

            ptr = ptr -> next;
        }

        ptr -> next = NewItem;
    }
}

void HashTable::ReadFile(const char *DocumentName) {

    std::cout << "Read data from file \"" << DocumentName << "\"" << std::endl;

    std::ifstream in(DocumentName);

    if (!in) {

        //const char *str = "Error! Unable to read file \"" + DocumentName + "\": ";

    	perror("ErrorFile: ");

        return;
    }

    bool fflag(true);

    cell* NewCell = new cell;

    //
    int i(0);
    //

    while (fflag) {

    	in >> NewCell -> surname;
        in >> NewCell -> name;
        in >> NewCell -> patronymic;
        in >> NewCell -> cash;

/*        std::cout << "______________________________" << std::endl;
        std::cout << "key = " << Hash(NewCell) << std::endl;
        std::cout << "Surname:\t" << NewCell -> surname << std::endl;
        std::cout << "Name:\t\t" << NewCell -> name << std::endl;
        std::cout << "Patronymic:\t" << NewCell -> patronymic << std::endl;
        std::cout << "Cash:\t\t" << NewCell -> cash << std::endl;
        std::cout << "______________________________" << std::endl;
*/
      	if (i % 1000 == 0) std::cout << i << " step" << std::endl;

      	++i;

        if(in.eof()) {

            fflag = false;

        } else {

            Add(NewCell);
        }
    }

    in.close();

    delete NewCell;

    std::cout << "Data successfully read. The file \"" << DocumentName << "\" was closed." << std::endl;
}

void HashTable::Print() {

    for (unsigned int index(0); index < TableSize; ++index) {

        if (DataBase[index] != nullptr) {

            if (DataBase[index] -> next == nullptr) {

//            	std::cout << DataBase[index] << std::endl;

                std::cout << "______________________________" << std::endl;
                std::cout << "Surname:\t" << DataBase[index] -> surname << std::endl;
                std::cout << "Name:\t\t" << DataBase[index] -> name << std::endl;
                std::cout << "Patronymic:\t" << DataBase[index] -> patronymic << std::endl;
                std::cout << "Cash:\t\t" << DataBase[index] -> cash << std::endl;
                std::cout << "______________________________" << std::endl;
   
            } else {

                cell *ptr = DataBase[index];

                while (ptr != nullptr) {

//                	std::cout << ptr << std::endl;

                    std::cout << "______________________________" << std::endl;
                    std::cout << "Surname:\t" << ptr -> surname << std::endl;
                    std::cout << "Name:\t\t" << ptr -> name << std::endl;
                    std::cout << "Patronymic:\t" << ptr -> patronymic << std::endl;
                    std::cout << "Cash:\t\t" << ptr -> cash << std::endl;
                    std::cout << "______________________________" << std::endl;

                    ptr = ptr -> next;
                }
            }
        }
    }
}

bool HashTable::Find(cell *DesiredCell) {

    int key = Hash(DesiredCell);

    cell* ptr = DataBase[key];

    while(ptr != nullptr) {

    	if(Equal(ptr, DesiredCell)) {

    		return true;
    	}
    }

    return false;
}

bool HashTable::RemoveCell(cell* DesiredCell){

    int key = Hash(DesiredCell);
    cell* del_ptr;

//  this cell is empty
    if (DataBase[key] == nullptr) {

        return false;
    }

//  this cell is not empty and desired cell is located here
    if (DataBase[key] == DesiredCell) {

        del_ptr = DataBase[key];
        DataBase[key] = DataBase[key] -> next;

        delete del_ptr;
        return true;
    }

//  pointer, this cell will be remove

    del_ptr = DataBase[key] -> next;

//  left pointer, this cell need to remove del_ptr

    cell* left_ptr = DataBase[key];

//  this loop search desired cell
    while ((del_ptr -> next != nullptr) || (del_ptr != DesiredCell)) {

        del_ptr = del_ptr -> next;
        left_ptr = left_ptr -> next;
    }

//  desired cell was not found in hash table in this key after while
    if (del_ptr == nullptr) {

        return false;
    }

//  desired cell was found in hash table in this key
    if (del_ptr == DesiredCell){

        left_ptr -> next = del_ptr -> next;

        delete del_ptr;
        return true;
    }

    return false;
}

HashTable::~HashTable() {

    cell* ptr;

    for (unsigned int index(0); index < TableSize; ++index) {

        ptr = DataBase[index];

        while (ptr != nullptr) {

            cell* del_ptr = ptr;
            delete del_ptr;

            ptr = ptr -> next;
        }

        DataBase[index] = nullptr;
    }

    std::cout << "Hash table was successfully removed." << std::endl;
}

bool HashTable::Equal(cell* l, cell* r) {

    if ((l -> surname == r -> surname)
        && (l -> name == r -> name)
        && (l -> patronymic == r -> patronymic)
        && (l -> cash == r -> cash)) { return true; } else { return false; }
}