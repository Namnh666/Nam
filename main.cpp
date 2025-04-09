#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct MonAn {
    string ma;
    string ten;
    double gia;
    string loai;
};

struct HoaDon {
    string ma;
    string maBan;
    string maNV;
    double tongTien;
    string ngayLap;
};

struct LoaiMon {
    string ma;
    string ten;
};

struct NhanVien {
    string ma;
    string ten;
    string sdt;
};

struct BanAn {
    string ma;
    int soCho;
    bool trangThai;
};

vector<MonAn> dsMonAn;
vector<HoaDon> dsHoaDon;
vector<LoaiMon> dsLoaiMon;
vector<NhanVien> dsNhanVien;
vector<BanAn> dsBanAn;

void docFileMonAn() {
    ifstream in("monan.txt");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string ma, ten, loai;
        double gia;
        getline(ss, ma, ','); getline(ss, ten, ','); ss >> gia; ss.ignore(); getline(ss, loai);
        dsMonAn.push_back({ma, ten, gia, loai});
    }
    in.close();
}

void docFileHoaDon() {
    ifstream in("hoadon.txt");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string ma, maBan, maNV, ngay;
        double tong;
        getline(ss, ma, ','); getline(ss, maBan, ','); getline(ss, maNV, ','); ss >> tong; ss.ignore(); getline(ss, ngay);
        dsHoaDon.push_back({ma, maBan, maNV, tong, ngay});
    }
    in.close();
}

void docFileLoaiMon() {
    ifstream in("loaimon.txt");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string ma, ten;
        getline(ss, ma, ','); getline(ss, ten);
        dsLoaiMon.push_back({ma, ten});
    }
    in.close();
}

void docFileNhanVien() {
    ifstream in("nhanvien.txt");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string ma, ten, sdt;
        getline(ss, ma, ','); getline(ss, ten, ','); getline(ss, sdt);
        dsNhanVien.push_back({ma, ten, sdt});
    }
    in.close();
}

void docFileBanAn() {
    ifstream in("banan.txt");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string ma; int soCho; bool trangThai;
        getline(ss, ma, ','); ss >> soCho; ss.ignore(); ss >> trangThai;
        dsBanAn.push_back({ma, soCho, trangThai});
    }
    in.close();
}
void menuMonAn() {
    int chon;
    do {
        cout << "\n=== QUAN LY MON AN ===\n";
        cout << "1. Xem danh sach mon an\n";
        cout << "2. Them mon an\n";
        cout << "3. Sua mon an\n";
        cout << "4. Xoa mon an\n";
        cout << "0. Quay lai\nChon: ";
        cin >> chon;
        cin.ignore();
        if (chon == 1) {
            for (const auto &m : dsMonAn)
                cout << m.ma << " - " << m.ten << " - " << fixed << setprecision(2) << m.gia << " - " << m.loai << endl;
        } else if (chon == 2) {
            MonAn m;
            cout << "Nhap ma: "; getline(cin, m.ma);
            cout << "Nhap ten: "; getline(cin, m.ten);
            cout << "Nhap gia: "; cin >> m.gia; cin.ignore();
            cout << "Nhap loai: "; getline(cin, m.loai);
            dsMonAn.push_back(m);
            ofstream out("monan.txt");
            for (const auto &mon : dsMonAn)
                out << mon.ma << "," << mon.ten << "," << mon.gia << "," << mon.loai << "\n";
            out.close();
            cout << "Da them mon an!\n";
        } else if (chon == 3) {
            string ma;
            cout << "Nhap ma mon an can sua: "; getline(cin, ma);
            bool found = false;
            for (auto &m : dsMonAn) {
                if (m.ma == ma) {
                    cout << "Nhap ten moi: "; getline(cin, m.ten);
                    cout << "Nhap gia moi: "; cin >> m.gia; cin.ignore();
                    cout << "Nhap loai moi: "; getline(cin, m.loai);
                    found = true;
                    break;
                }
            }
            if (found) {
                ofstream out("monan.txt");
                for (const auto &mon : dsMonAn)
                    out << mon.ma << "," << mon.ten << "," << mon.gia << "," << mon.loai << "\n";
                out.close();
                cout << "Da cap nhat mon an!\n";
            } else {
                cout << "Khong tim thay mon an!\n";
            }
        } else if (chon == 4) {
            string ma;
            cout << "Nhap ma mon an can xoa: "; getline(cin, ma);
            auto it = remove_if(dsMonAn.begin(), dsMonAn.end(), [&](const MonAn &m) {
                return m.ma == ma;
            });
            if (it != dsMonAn.end()) {
                dsMonAn.erase(it, dsMonAn.end());
                ofstream out("monan.txt");
                for (const auto &mon : dsMonAn)
                    out << mon.ma << "," << mon.ten << "," << mon.gia << "," << mon.loai << "\n";
                out.close();
                cout << "Da xoa mon an!\n";
            } else {
                cout << "Khong tim thay mon an!\n";
            }
        }
    } while (chon != 0);
}

void menuLoaiMon() {
    int chon;
    do {
        cout << "\n=== QUAN LY LOAI MON ===\n";
        cout << "1. Xem danh sach loai mon\n";
        cout << "2. Them loai mon\n";
        cout << "3. Sua loai mon\n";
        cout << "4. Xoa loai mon\n";
        cout << "0. Quay lai\nChon: ";
        cin >> chon;
        cin.ignore();
        if (chon == 1) {
            for (const auto &lm : dsLoaiMon)
                cout << lm.ma << " - " << lm.ten << endl;
        } else if (chon == 2) {
            LoaiMon lm;
            cout << "Nhap ma: "; getline(cin, lm.ma);
            cout << "Nhap ten: "; getline(cin, lm.ten);
            dsLoaiMon.push_back(lm);
            ofstream out("loaimon.txt");
            for (const auto &loai : dsLoaiMon)
                out << loai.ma << "," << loai.ten << "\n";
            out.close();
            cout << "Da them loai mon!\n";
        } else if (chon == 3) {
            string ma;
            cout << "Nhap ma loai mon can sua: "; getline(cin, ma);
            bool found = false;
            for (auto &lm : dsLoaiMon) {
                if (lm.ma == ma) {
                    cout << "Nhap ten moi: "; getline(cin, lm.ten);
                    found = true;
                    break;
                }
            }
            if (found) {
                ofstream out("loaimon.txt");
                for (const auto &loai : dsLoaiMon)
                    out << loai.ma << "," << loai.ten << "\n";
                out.close();
                cout << "Da cap nhat loai mon!\n";
            } else {
                cout << "Khong tim thay loai mon!\n";
            }
        } else if (chon == 4) {
            string ma;
            cout << "Nhap ma loai mon can xoa: "; getline(cin, ma);
            auto it = remove_if(dsLoaiMon.begin(), dsLoaiMon.end(), [&](const LoaiMon &lm) {
                return lm.ma == ma;
            });
            if (it != dsLoaiMon.end()) {
                dsLoaiMon.erase(it, dsLoaiMon.end());
                ofstream out("loaimon.txt");
                for (const auto &loai : dsLoaiMon)
                    out << loai.ma << "," << loai.ten << "\n";
                out.close();
                cout << "Da xoa loai mon!\n";
            } else {
                cout << "Khong tim thay loai mon!\n";
            }
        }
    } while (chon != 0);
}

void menuNhanVien() {
    int chon;
    do {
        cout << "\n=== QUAN LY NHAN VIEN ===\n";
        cout << "1. Xem danh sach nhan vien\n";
        cout << "2. Them nhan vien\n";
        cout << "3. Sua nhan vien\n";
        cout << "4. Xoa nhan vien\n";
        cout << "0. Quay lai\nChon: ";
        cin >> chon;
        cin.ignore();

        if (chon == 1) {
            for (const auto &nv : dsNhanVien)
                cout << nv.ma << " - " << nv.ten << " - " << nv.sdt << endl;

        } else if (chon == 2) {
            NhanVien nv;
            cout << "Nhap ma: "; getline(cin, nv.ma);
            cout << "Nhap ten: "; getline(cin, nv.ten);
            cout << "Nhap so dien thoai: "; getline(cin, nv.sdt);
            dsNhanVien.push_back(nv);
            ofstream out("nhanvien.txt");
            for (const auto &n : dsNhanVien)
                out << n.ma << "," << n.ten << "," << n.sdt << "\n";
            out.close();
            cout << "Da them nhan vien!\n";

        } else if (chon == 3) {
            string ma;
            cout << "Nhap ma nhan vien can sua: "; getline(cin, ma);
            bool found = false;
            for (auto &nv : dsNhanVien) {
                if (nv.ma == ma) {
                    cout << "Nhap ten moi: "; getline(cin, nv.ten);
                    cout << "Nhap sdt moi: "; getline(cin, nv.sdt);
                    found = true;
                    break;
                }
            }
            if (found) {
                ofstream out("nhanvien.txt");
                for (const auto &n : dsNhanVien)
                    out << n.ma << "," << n.ten << "," << n.sdt << "\n";
                out.close();
                cout << "Da cap nhat nhan vien!\n";
            } else {
                cout << "Khong tim thay nhan vien!\n";
            }

        } else if (chon == 4) {
            string ma;
            cout << "Nhap ma nhan vien can xoa: "; getline(cin, ma);
            auto it = remove_if(dsNhanVien.begin(), dsNhanVien.end(), [&](const NhanVien &nv) {
                return nv.ma == ma;
            });
            if (it != dsNhanVien.end()) {
                dsNhanVien.erase(it, dsNhanVien.end());
                ofstream out("nhanvien.txt");
                for (const auto &n : dsNhanVien)
                    out << n.ma << "," << n.ten << "," << n.sdt << "\n";
                out.close();
                cout << "Da xoa nhan vien!\n";
            } else {
                cout << "Khong tim thay nhan vien!\n";
            }
        }
    } while (chon != 0);
}

void menuBanAn() {
    int chon;
    do {
        cout << "\n=== QUAN LY BAN AN ===\n";
        cout << "1. Xem danh sach ban an\n";
        cout << "2. Them ban an\n";
        cout << "3. Sua ban an\n";
        cout << "4. Xoa ban an\n";
        cout << "0. Quay lai\nChon: ";
        cin >> chon;
        cin.ignore();

        if (chon == 1) {
            for (const auto &b : dsBanAn)
                cout << b.ma << " - So cho: " << b.soCho << " - Trang thai: " << (b.trangThai ? "Co nguoi" : "Trong") << endl;

        } else if (chon == 2) {
            BanAn b;
            cout << "Nhap ma ban: "; getline(cin, b.ma);
            cout << "Nhap so cho: "; cin >> b.soCho;
            cout << "Trang thai (0 = Trong, 1 = Co nguoi): "; cin >> b.trangThai;
            cin.ignore();
            dsBanAn.push_back(b);
            ofstream out("banan.txt");
            for (const auto &ba : dsBanAn)
                out << ba.ma << "," << ba.soCho << "," << ba.trangThai << "\n";
            out.close();
            cout << "Da them ban an!\n";

        } else if (chon == 3) {
            string ma;
            cout << "Nhap ma ban an can sua: "; getline(cin, ma);
            bool found = false;
            for (auto &b : dsBanAn) {
                if (b.ma == ma) {
                    cout << "Nhap so cho moi: "; cin >> b.soCho;
                    cout << "Trang thai moi (0 = Trong, 1 = Co nguoi): "; cin >> b.trangThai;
                    cin.ignore();
                    found = true;
                    break;
                }
            }
            if (found) {
                ofstream out("banan.txt");
                for (const auto &ba : dsBanAn)
                    out << ba.ma << "," << ba.soCho << "," << ba.trangThai << "\n";
                out.close();
                cout << "Da cap nhat ban an!\n";
            } else {
                cout << "Khong tim thay ban an!\n";
            }

        } else if (chon == 4) {
            string ma;
            cout << "Nhap ma ban an can xoa: "; getline(cin, ma);
            auto it = remove_if(dsBanAn.begin(), dsBanAn.end(), [&](const BanAn &b) {
                return b.ma == ma;
            });
            if (it != dsBanAn.end()) {
                dsBanAn.erase(it, dsBanAn.end());
                ofstream out("banan.txt");
                for (const auto &ba : dsBanAn)
                    out << ba.ma << "," << ba.soCho << "," << ba.trangThai << "\n";
                out.close();
                cout << "Da xoa ban an!\n";
            } else {
                cout << "Khong tim thay ban an!\n";
            }
        }
    } while (chon != 0);
}

void inHoaDon(const string& maHD) {
    bool found = false;
    for (const auto &hd : dsHoaDon) {
        if (hd.ma == maHD) {
            cout << "\n--- HOA DON ---\n";
            cout << "Ma HD: " << hd.ma << "\n";
            cout << "Ma ban: " << hd.maBan << "\n";
            cout << "Ma NV: " << hd.maNV << "\n";
            cout << "Tong tien: " << fixed << setprecision(2) << hd.tongTien << "\n";
            cout << "Ngay lap: " << hd.ngayLap << "\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay hoa don!\n";
}

void menuHoaDon() {
    int chon;
    do {
        cout << "\n=== QUAN LY HOA DON ===\n";
        cout << "1. Xem danh sach hoa don\n";
        cout << "2. In hoa don theo ma\n";
        cout << "3. Them hoa don\n";
        cout << "4. Sua hoa don\n";
        cout << "5. Xoa hoa don\n";
        cout << "0. Quay lai\nChon: ";
        cin >> chon;
        cin.ignore();
        if (chon == 1) {
            for (const auto &hd : dsHoaDon)
                cout << hd.ma << " - " << hd.maBan << " - " << hd.maNV << " - " << fixed << setprecision(2) << hd.tongTien << " - " << hd.ngayLap << endl;
        } else if (chon == 2) {
            string ma;
            cout << "Nhap ma hoa don: ";
            getline(cin, ma);
            inHoaDon(ma);
        } else if (chon == 3) {
            HoaDon hd;
            cout << "Nhap ma hoa don: "; getline(cin, hd.ma);
            cout << "Nhap ma ban: "; getline(cin, hd.maBan);
            cout << "Nhap ma nhan vien: "; getline(cin, hd.maNV);
            cout << "Nhap tong tien: "; cin >> hd.tongTien; cin.ignore();
            cout << "Nhap ngay lap (dd/mm/yyyy): "; getline(cin, hd.ngayLap);
            dsHoaDon.push_back(hd);
            ofstream out("hoadon.txt");
            for (const auto &h : dsHoaDon)
                out << h.ma << "," << h.maBan << "," << h.maNV << "," << h.tongTien << "," << h.ngayLap << "\n";
            out.close();
            cout << "Da them hoa don!\n";

        } else if (chon == 4) {
            string ma;
            cout << "Nhap ma hoa don can sua: "; getline(cin, ma);
            bool found = false;
            for (auto &hd : dsHoaDon) {
                if (hd.ma == ma) {
                    cout << "Nhap ma ban moi: "; getline(cin, hd.maBan);
                    cout << "Nhap ma nhan vien moi: "; getline(cin, hd.maNV);
                    cout << "Nhap tong tien moi: "; cin >> hd.tongTien; cin.ignore();
                    cout << "Nhap ngay lap moi: "; getline(cin, hd.ngayLap);
                    found = true;
                    break;
                }
            }
            if (found) {
                ofstream out("hoadon.txt");
                for (const auto &h : dsHoaDon)
                    out << h.ma << "," << h.maBan << "," << h.maNV << "," << h.tongTien << "," << h.ngayLap << "\n";
                out.close();
                cout << "Da cap nhat hoa don!\n";
            } else {
                cout << "Khong tim thay hoa don!\n";
            }

        } else if (chon == 5) {
            string ma;
            cout << "Nhap ma hoa don can xoa: "; getline(cin, ma);
            auto it = remove_if(dsHoaDon.begin(), dsHoaDon.end(), [&](const HoaDon &hd) {
                return hd.ma == ma;
            });
            if (it != dsHoaDon.end()) {
                dsHoaDon.erase(it, dsHoaDon.end());
                ofstream out("hoadon.txt");
                for (const auto &h : dsHoaDon)
                    out << h.ma << "," << h.maBan << "," << h.maNV << "," << h.tongTien << "," << h.ngayLap << "\n";
                out.close();
                cout << "Da xoa hoa don!\n";
            } else {
                cout << "Khong tim thay hoa don!\n";
            }
        }
    } while (chon != 0);
}

void baoCaoDoanhThu() {
    int loai;
    cout << "\n=== BAO CAO DOANH THU ===\n";
    cout << "1. Theo ngay (dd/mm/yyyy)\n";
    cout << "2. Theo thang (mm/yyyy)\n";
    cout << "3. Theo nam (yyyy)\n";
    cout << "0. Quay lai\nChon: ";
    cin >> loai;
    cin.ignore();
    string timeInput;
    double tong = 0;

    if (loai == 1) {
        cout << "Nhap ngay (dd/mm/yyyy): ";
        getline(cin, timeInput);
        for (const auto &hd : dsHoaDon) {
            if (hd.ngayLap == timeInput) {
                tong += hd.tongTien;
            }
        }
        cout << "Tong doanh thu ngay " << timeInput << ": " << fixed << setprecision(2) << tong << " VND\n";
    } else if (loai == 2) {
        cout << "Nhap thang (mm/yyyy): ";
        getline(cin, timeInput);
        for (const auto &hd : dsHoaDon) {
            if (hd.ngayLap.substr(3, 7) == timeInput) {
                tong += hd.tongTien;
            }
        }
        cout << "Tong doanh thu thang " << timeInput << ": " << fixed << setprecision(2) << tong << " VND\n";
    } else if (loai == 3) {
        cout << "Nhap nam (yyyy): ";
        getline(cin, timeInput);
        for (const auto &hd : dsHoaDon) {
            if (hd.ngayLap.substr(6, 4) == timeInput) {
                tong += hd.tongTien;
            }
        }
        cout << "Tong doanh thu nam " << timeInput << ": " << fixed << setprecision(2) << tong << " VND\n";
    } else if (loai == 0) {
        return;
    } else {
        cout << "Lua chon khong hop le!\n";
    }
}

// menuChinh()
void menuChinh() {
    // docFile...
    docFileMonAn();
    docFileHoaDon();
    docFileLoaiMon();
    docFileNhanVien();
    docFileBanAn();
    int chon;
    do {
        cout << "\n=== MENU CHINH ===\n";
        cout << "1. Quan ly mon an\n";
        cout << "2. Quan ly loai mon\n";
        cout << "3. Quan ly nhan vien\n";
        cout << "4. Quan ly ban an\n";
        cout << "5. Quan ly hoa don\n";
        cout << "6. Bao cao doanh thu\n";
        cout << "0. Thoat\nChon: ";
        cin >> chon;
        cin.ignore();
        switch (chon) {
            case 1: menuMonAn(); break;
            case 2: menuLoaiMon(); break;
            case 3: menuNhanVien(); break;
            case 4: menuBanAn(); break;
            case 5: menuHoaDon(); break;
            case 6: baoCaoDoanhThu(); break;
            case 0: cout << "Tam biet!\n"; break;
            default: cout << "Lua chon khong hop le!\n";
        }
    } while (chon != 0);
}

int main() {
    menuChinh();
    return 0;
}
