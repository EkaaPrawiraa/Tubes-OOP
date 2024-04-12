#include "Role/Role.hpp"

// dapat storrows dan storcols dari miscConfig
Role::Role(string username, float weight, int uang, MiscConfig &configGame)
    : username(username), weight(weight), gulden(uang), invent(0, 0) // 0,0 hanya untuk default constructor invent
{
    // dapat storrows dan storcols dari miscConfig
    int storrows = configGame.getStorageRows();
    int storcols = configGame.getStorageCols();
    invent = Matrix<Item *>(storrows, storcols);
}

Role::~Role() {}
void Role::next()
{
}
void Role::cetak_penyimpanan()
{
    invent.display("Penyimpanan");
}
void Role::makan()
{
    if (invent.isempty())
    {
        // EXCEPTION
        cout << "Inventori Kosong" << endl;
        return;
    }
    bool foundfood = false;
    for (const auto &row : invent.getmatrix())
    {
        for (const auto &cell : row.second)
        {
            if (auto product = dynamic_cast<Product *>(cell.second))
            {
                if (product->getadded_weight() != 0)
                {
                    foundfood = true;
                    break;
                }
            }
        }
        if (foundfood)
        {
            break;
        }
    }
    if (!foundfood)
    {
        // EXCEPTION BUAT
        cout << "Tidak ada makanan di inventori" << endl;
        return;
    }
    cout << "Pilih makanan dari penyimpanan" << endl;
    cetak_penyimpanan();
    cout << endl
         << endl;
    string lokasi;
    bool found;
    int gain;
    do
    {
        std::cout << "Slot: ";
        std::cin >> lokasi;
        char column = lokasi[0];
        int row = stoi(lokasi.substr(1));
        found = false;
        if (auto product = dynamic_cast<Product *>(invent.getmatrix()[row][column]))
        {
            if (product->getadded_weight() != 0)
            {
                found = true;
                gain = product->getadded_weight();
                invent.deleteValue(row, column);
            }
        }

        if (!found)
        {
            // THROW EXCEPTION
            std::cout << "Tidak ditemukan makanan di lokasi" << std::endl;
        }

    } while (!found);
    this->weight += gain;
}
void Role::membeli()
{
}
void Role::menjual()
{
}
int Role::getGulden()
{
    return gulden;
}
float Role::getWeight()
{
    return weight;
}
void Role::setGulden(int gulden)
{
    this->gulden = gulden;
}
void Role::setWeight(float weight)
{
    this->weight = weight;
}
