#include <iostream>
#include <vector>
#include <string>
using namespace std;

class staff {
private:
    string maNV;
    string name;
    string room;
    string date;
    double HSL;
    double BHTN;
    double Salary;
    double BHYT;
    double BHXH;
    double thucLinh;

public:
    // constructors
    staff() {};
    staff(string maNV, string name, string room, string date, double HSL, double BHTN, double Salary, double BHYT, double BHXH, double thucLinh) {
       setMaNV(maNV);
        setName(name);
        setRoom(room);
        setDate(date);
        setHSL(HSL);
        setBHTN(BHTN);
        setSalary(Salary);
        setBHYT(BHYT);
        setBHXH(BHXH);
        setThucLinh(thucLinh);
    }

    // getters setters
    string getMaNV() {
        return maNV;
    }
    void setMaNV(string maNV) {
        this->maNV = maNV;
    }
    string getName() {
        return name;
    }
    void setName(string name) {
        this->name = name;
    }
    string getRoom() {
        return room;
    }
    void setRoom(string room) {
        for (char &ch : room) {
            ch = toupper(ch);
        }

        if (room != "A" && room != "B" && room != "C" && room != "D") {
            return;
        }
        this->room = room;
    }

    string getDate() {
        return date;
    }
    void setDate(string date) {
        this->date = date;
    }
    double getHSL() {
        return HSL;
    }
    void setHSL(double HSL) {
        this->HSL = HSL;
    }
    double getBHTN() {
        return BHTN;
    }
    void setBHTN(double BHTN) {
        this->BHTN = BHTN;
    }
    double getSalary() {
        return Salary;
    }
    void setSalary(double Salary) {
        this->Salary = Salary;
    }
    double getBHYT() {
        return BHYT;
    }
    void setBHYT(double BHYT) {
        this->BHYT = BHYT;
    }

    double getBHXH() {
        return BHXH;
    }
    void setBHXH(double BHXH) {
        this->BHXH = BHXH;
    }
    double getThucLinh() {
        return thucLinh;
    }
    void setThucLinh(double thucLinh) {
        this->thucLinh = thucLinh;
    }
}; 

//xay dung class quan ly danh sach nhan vien bang vector 
class manageStaff {
    private:
    vector<staff> m_staff;
     public:
     //constructor:
    manageStaff() {};
    //method:

    // nhap danh sach sinh vien va them vao vector : 
    void addStaff() {
        string maNV;
        string name;
        string room;
        string date;
        double HSL;
        double BHTN;
        double Salary;
        double BHYT;
        double BHXH;
        double thucLinh;
        cout << "Nhap maNV: ";
        cin >> maNV;
        cout << "Nhap name: ";
        getline(cin, name);
        cout << "Nhap room: ";
        cin >> room;
        cout << "Nhap date: ";
        cin >> date;
        cout << "Nhap HSL: ";
        cin >> HSL;
        cout << "Nhap Salary: ";
        cin >> Salary;
        BHTN = 0.01*Salary;
        BHYT = 0.05*Salary;
        BHXH = 0.1*Salary;
        staff newStaff(maNV, name, room, date,HSL, BHTN,Salary,BHYT,BHXH,thucLinh);
        m_staff.push_back(newStaff);
    }

    //them 1 staff vao vector de quan ly 
    void addStaff(const staff &newStaff) {
        m_staff.push_back(newStaff);
     }

    //searchByName
    void searchByName(string name) {
        for (int i = 0; i < m_staff.size(); i++) {
            if (m_staff[i].getName() == name) {
                cout << "found" <<endl;
                return;
            }
        }
        cout << "not found" <<endl;
        return;
    }

    //tinh luong binh quan theo phong ban 
    void tinhLuongBinhQuan() {
        double sumA , sumB , sumC ,sumD ; 
        int quantityA , quantityB , quantityC , quantityD;
        int n = m_staff.size();
        for(int i = 0 ;  i < n ; i++) {
            if (m_staff[i].getRoom() == "A") {
                sumA += m_staff[i].getSalary();
                quantityA++;
            }
            if (m_staff[i].getRoom() == "B") {
                sumB += m_staff[i].getSalary();
                quantityB++;
            }
            if (m_staff[i].getRoom() == "C") {
                sumC += m_staff[i].getSalary();
                quantityC++;
            }
            if (m_staff[i].getRoom() == "D") {
                sumD += m_staff[i].getSalary();
                quantityD++;
            }
        }
        cout << "Average A : " << (sumA/quantityA) << endl;
        cout << "Average B : " << (sumB/quantityB) << endl;
        cout << "Average C : " << (sumC/quantityC) << endl;
        cout << "Average D : " << (sumD/quantityD) << endl;
    }

    //tim nhan vien co luong thap nhat 
    void timNhanVienCoLuongThapNhat() {
        double max = m_staff[0].getSalary();
        int index = 0;
        for (int i = 0; i < m_staff.size(); i++) {
            if (m_staff[i].getSalary() > max) {
                max = m_staff[i].getSalary();
                index = i;
            }
        }
        cout << "Nhan vien co luong thap nhat: " << m_staff[index].getName() << endl;
    }

    //in danh sach theo thu tu giam dan cua luong 
    void inNhanVienGiamDan() {
        int n = m_staff.size();
        int minIndex;
        for (int i = 0; i < n - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (m_staff[j].getSalary() < m_staff[minIndex].getSalary()) {
                    minIndex = j;
                }
            }
            swap(m_staff[i], m_staff[minIndex]);
        }
        for (int i = 0; i < n; i++) {
            cout << m_staff[i].getName() << endl;
        }
    }

};


int main() {
    manageStaff manager;
    // Thêm các dòng code để thực hiện các chức năng, ví dụ:
    manager.addStaff();
    manager.addStaff();
    manager.inNhanVienGiamDan();
}
