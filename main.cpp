// hash.cpp

#include <cstring>
#include <iostream>
#include <math.h>

using namespace std;

// the most things we can store in the table
const int MAX_SIZE = 2000;

// a product with a code & price
struct Product {
    Product(const char* a = "", const char* b = "") {
        strcpy(code, a);
        strcpy(price, b);
    }
    char code[100];
    char price[15];
};

// the hash table class
class HashTable {
public:
    // set all linked lists to empty
    HashTable() {
        for(int i = 0; i < MAX_SIZE; i++) {
            inventory[i] = NULL;
        }
    }

    // insert a product
    void insert(Product p) {
        // hash the product
        int index = hash(p.code);

        // make a new node at the start of this list
        Node* node = new Node;
        node->product = p;
        node->next = inventory[index];
        inventory[index] = node;

        cout << "Inserted " << p.code << " at " << index << endl;
    }


    // lookup a product's price
    void lookup(const char* code) {
        // hash the product
        int index = hash(code);

        // look for them at this linked list
        Node* current = inventory[index];
        int number = 0;
        while(strcmp(current->product.code, code) != 0) {
            number++;
            current = current->next;
        }

        cout << "Found " << code << " in slot " << index << ", node " << number << endl;
    }

    // hash a string into am index
    int hash(const char* code) {
        int value = 0;
        // add up all the ASCII values
        for(unsigned int i = 0; i < strlen(code); i++) {
            value = value + code[i];
            //certain combination of letters can occur multiple times or the addition of certain numbers may be the same therefore, it would be good to increase value of letter as place value increase
            // value = value + code[i] + ((90 - code[i])*(i+(value%10))); // good
            // value = value + code[i] + ((90 - code[i])*(i+(code[i]%10))); //better
            //value = (value + (code[i]))*code[i]; // best //1.2438
            //value = value + (pow((code[i]), i))*code[i]; //best //1.24069
            value = value + pow((code[i]),i); //best //1.22549 !!!
        }

        // mod by size to prevent overflow
        return value % MAX_SIZE;
    }

    // report how good the hashing was
    void report() {
        // find largest list
        int max = 0;
        int total = 0;
        int num_filled = 0;

        for(int i = 0; i < MAX_SIZE; i++) {
            int size = 0;
            Node* current = inventory[i];
            while(current) {
                size++;
                current = current->next;
            }
            if(size > 0) {
                num_filled++;
                total += size;
            }
            if(size > max) {
                max = size;
            }
        }
        cout << "The table has " << total << " elements." << endl;
        cout << num_filled << " lists have data out of " << MAX_SIZE << " total." << endl;
        cout << "The average filled list has " << ((float)total / num_filled) << " elements." << endl;
        cout << "Largest list has " << max << " elements." << endl;
    }

private:
    // a node in one of our linked lists
    struct Node {
        Product product;
        Node* next;
    };

    // the products are all stored in an array
    Node* inventory[MAX_SIZE];
};


// main program
int main() {
    HashTable table;

    // insert 500 products
    table.insert(Product("QPT", "$871.73"));
    table.insert(Product("QYQ", "$783.66"));
    table.insert(Product("IPY", "$737.96"));
    table.insert(Product("IKJ", "$872.22"));
    table.insert(Product("POW", "$750.51"));
    table.insert(Product("OEF", "$646.31"));
    table.insert(Product("MBF", "$956.11"));
    table.insert(Product("ERJ", "$666.93"));
    table.insert(Product("XJG", "$472.71"));
    table.insert(Product("BKC", "$394.58"));
    table.insert(Product("HPP", "$417.64"));
    table.insert(Product("CSP", "$940.95"));
    table.insert(Product("HAW", "$498.46"));
    table.insert(Product("PSU", "$590.21"));
    table.insert(Product("HQF", "$965.37"));
    table.insert(Product("QHL", "$904.29"));
    table.insert(Product("TFS", "$223.80"));
    table.insert(Product("OUP", "$731.40"));
    table.insert(Product("BIF", "$797.89"));
    table.insert(Product("KTD", "$737.10"));
    table.insert(Product("NZU", "$228.70"));
    table.insert(Product("EST", "$132.97"));
    table.insert(Product("AUW", "$344.39"));
    table.insert(Product("ELH", "$170.83"));
    table.insert(Product("RTM", "$972.33"));
    table.insert(Product("QAX", "$987.70"));
    table.insert(Product("HOH", "$289.60"));
    table.insert(Product("QYA", "$319.19"));
    table.insert(Product("SSA", "$817.39"));
    table.insert(Product("RMA", "$170.70"));
    table.insert(Product("FTM", "$397.95"));
    table.insert(Product("WMK", "$509.82"));
    table.insert(Product("HWC", "$305.83"));
    table.insert(Product("QLI", "$561.91"));
    table.insert(Product("ZPV", "$791.73"));
    table.insert(Product("CWN", "$448.77"));
    table.insert(Product("QYZ", "$633.76"));
    table.insert(Product("YWV", "$111.74"));
    table.insert(Product("GTS", "$235.16"));
    table.insert(Product("YMF", "$328.85"));
    table.insert(Product("TOC", "$383.39"));
    table.insert(Product("HEX", "$642.15"));
    table.insert(Product("EJR", "$163.64"));
    table.insert(Product("YFA", "$185.75"));
    table.insert(Product("FLX", "$846.82"));
    table.insert(Product("OIW", "$758.58"));
    table.insert(Product("NMA", "$893.85"));
    table.insert(Product("QIN", "$898.52"));
    table.insert(Product("ZYL", "$477.42"));
    table.insert(Product("TTP", "$180.38"));
    table.insert(Product("ZBR", "$133.42"));
    table.insert(Product("XMQ", "$781.72"));
    table.insert(Product("LRT", "$838.27"));
    table.insert(Product("KHW", "$947.29"));
    table.insert(Product("ZFJ", "$957.59"));
    table.insert(Product("JOW", "$337.64"));
    table.insert(Product("SYK", "$575.11"));
    table.insert(Product("XIG", "$786.36"));
    table.insert(Product("AMW", "$589.38"));
    table.insert(Product("EQK", "$975.21"));
    table.insert(Product("UOJ", "$801.42"));
    table.insert(Product("QQQ", "$415.85"));
    table.insert(Product("VVH", "$883.16"));
    table.insert(Product("GMD", "$142.33"));
    table.insert(Product("QOG", "$620.93"));
    table.insert(Product("TRW", "$646.34"));
    table.insert(Product("SBK", "$791.23"));
    table.insert(Product("XPX", "$661.18"));
    table.insert(Product("AFA", "$869.51"));
    table.insert(Product("KGG", "$633.61"));
    table.insert(Product("OEN", "$893.20"));
    table.insert(Product("RYR", "$861.91"));
    table.insert(Product("CVB", "$163.79"));
    table.insert(Product("OHH", "$104.20"));
    table.insert(Product("TRN", "$136.51"));
    table.insert(Product("QCI", "$682.18"));
    table.insert(Product("WIR", "$401.58"));
    table.insert(Product("RQM", "$605.67"));
    table.insert(Product("RWQ", "$524.83"));
    table.insert(Product("SQM", "$750.69"));
    table.insert(Product("ERN", "$484.34"));
    table.insert(Product("TRL", "$795.39"));
    table.insert(Product("YPI", "$864.14"));
    table.insert(Product("OIC", "$819.27"));
    table.insert(Product("VWH", "$854.29"));
    table.insert(Product("PGI", "$419.23"));
    table.insert(Product("LDT", "$265.42"));
    table.insert(Product("RDX", "$976.29"));
    table.insert(Product("BAL", "$727.56"));
    table.insert(Product("PQL", "$715.78"));
    table.insert(Product("RUJ", "$846.26"));
    table.insert(Product("JVF", "$339.69"));
    table.insert(Product("KWF", "$377.33"));
    table.insert(Product("NTM", "$678.95"));
    table.insert(Product("EIR", "$910.51"));
    table.insert(Product("SFP", "$628.75"));
    table.insert(Product("UTM", "$840.47"));
    table.insert(Product("UYO", "$932.10"));
    table.insert(Product("UWF", "$161.66"));
    table.insert(Product("FXW", "$581.66"));
    table.insert(Product("TYR", "$913.95"));
    table.insert(Product("QGI", "$418.52"));
    table.insert(Product("NQG", "$975.97"));
    table.insert(Product("SRO", "$317.41"));
    table.insert(Product("WBB", "$171.41"));
    table.insert(Product("NKZ", "$930.65"));
    table.insert(Product("EIU", "$511.90"));
    table.insert(Product("ENN", "$201.72"));
    table.insert(Product("URO", "$231.43"));
    table.insert(Product("THM", "$410.18"));
    table.insert(Product("LQI", "$979.85"));
    table.insert(Product("ZME", "$155.46"));
    table.insert(Product("LOL", "$488.71"));
    table.insert(Product("QVX", "$270.48"));
    table.insert(Product("HDN", "$685.80"));
    table.insert(Product("CUC", "$197.80"));
    table.insert(Product("MYK", "$537.74"));
    table.insert(Product("HZE", "$214.89"));
    table.insert(Product("CSH", "$288.32"));
    table.insert(Product("UKA", "$469.38"));
    table.insert(Product("CUW", "$530.69"));
    table.insert(Product("WOJ", "$612.73"));
    table.insert(Product("XZC", "$195.36"));
    table.insert(Product("LAA", "$488.90"));
    table.insert(Product("IUR", "$742.33"));
    table.insert(Product("GNI", "$728.68"));
    table.insert(Product("RVJ", "$175.56"));
    table.insert(Product("FRP", "$865.15"));
    table.insert(Product("TPJ", "$147.76"));
    table.insert(Product("PPE", "$999.50"));
    table.insert(Product("GTK", "$648.96"));
    table.insert(Product("ZTJ", "$622.71"));
    table.insert(Product("HGI", "$891.67"));
    table.insert(Product("DNW", "$472.77"));
    table.insert(Product("VFM", "$232.82"));
    table.insert(Product("OGZ", "$340.84"));
    table.insert(Product("BSH", "$622.33"));
    table.insert(Product("ORP", "$554.78"));
    table.insert(Product("KFU", "$559.79"));
    table.insert(Product("TWU", "$405.15"));
    table.insert(Product("FLH", "$251.57"));
    table.insert(Product("VGV", "$550.30"));
    table.insert(Product("QCV", "$234.13"));
    table.insert(Product("AQQ", "$841.86"));
    table.insert(Product("GWP", "$710.87"));
    table.insert(Product("PAN", "$624.67"));
    table.insert(Product("NLD", "$591.21"));
    table.insert(Product("TZM", "$223.84"));
    table.insert(Product("URB", "$238.17"));
    table.insert(Product("ZCV", "$551.28"));
    table.insert(Product("BCU", "$259.14"));
    table.insert(Product("PQN", "$922.95"));
    table.insert(Product("KYC", "$270.70"));
    table.insert(Product("FJW", "$680.97"));
    table.insert(Product("SMY", "$704.53"));
    table.insert(Product("AQD", "$679.99"));
    table.insert(Product("HGH", "$914.25"));
    table.insert(Product("MKO", "$786.76"));
    table.insert(Product("JDD", "$779.86"));
    table.insert(Product("GXE", "$604.55"));
    table.insert(Product("KAV", "$720.97"));
    table.insert(Product("WQJ", "$206.22"));
    table.insert(Product("ZVN", "$367.44"));
    table.insert(Product("IKK", "$179.95"));
    table.insert(Product("XRS", "$695.68"));
    table.insert(Product("HOM", "$794.97"));
    table.insert(Product("LXP", "$702.48"));
    table.insert(Product("ZWB", "$545.90"));
    table.insert(Product("VHZ", "$696.58"));
    table.insert(Product("BII", "$699.27"));
    table.insert(Product("NVG", "$667.91"));
    table.insert(Product("TZB", "$730.50"));
    table.insert(Product("FNJ", "$445.69"));
    table.insert(Product("CBE", "$824.41"));
    table.insert(Product("BVS", "$798.37"));
    table.insert(Product("KED", "$171.86"));
    table.insert(Product("PTS", "$892.40"));
    table.insert(Product("DXM", "$487.22"));
    table.insert(Product("UNW", "$469.70"));
    table.insert(Product("FXS", "$209.27"));
    table.insert(Product("MLH", "$311.28"));
    table.insert(Product("ARB", "$488.82"));
    table.insert(Product("VWP", "$775.70"));
    table.insert(Product("MLC", "$294.95"));
    table.insert(Product("DUJ", "$181.67"));
    table.insert(Product("MCD", "$162.63"));
    table.insert(Product("EHZ", "$408.18"));
    table.insert(Product("KUI", "$121.40"));
    table.insert(Product("UNZ", "$336.99"));
    table.insert(Product("MGX", "$647.98"));
    table.insert(Product("LGH", "$252.50"));
    table.insert(Product("EVI", "$272.79"));
    table.insert(Product("LOO", "$575.67"));
    table.insert(Product("CSI", "$923.23"));
    table.insert(Product("DEF", "$296.30"));
    table.insert(Product("TLW", "$705.56"));
    table.insert(Product("BSA", "$302.84"));
    table.insert(Product("OUM", "$104.52"));
    table.insert(Product("QHO", "$466.30"));
    table.insert(Product("HDA", "$394.91"));
    table.insert(Product("RVH", "$563.89"));
    table.insert(Product("LXI", "$400.91"));
    table.insert(Product("QXP", "$191.49"));
    table.insert(Product("FQP", "$571.79"));
    table.insert(Product("QMB", "$885.64"));
    table.insert(Product("OGV", "$982.45"));
    table.insert(Product("KGU", "$588.60"));
    table.insert(Product("JGL", "$121.90"));
    table.insert(Product("YYH", "$149.46"));
    table.insert(Product("DOI", "$320.56"));
    table.insert(Product("LMS", "$791.23"));
    table.insert(Product("DOB", "$464.48"));
    table.insert(Product("ESP", "$368.26"));
    table.insert(Product("DTR", "$592.35"));
    table.insert(Product("RKW", "$144.80"));
    table.insert(Product("EHH", "$554.95"));
    table.insert(Product("PSW", "$531.53"));
    table.insert(Product("NYN", "$437.84"));
    table.insert(Product("RTC", "$899.49"));
    table.insert(Product("INJ", "$447.72"));
    table.insert(Product("WDI", "$420.75"));
    table.insert(Product("PZU", "$396.13"));
    table.insert(Product("QVQ", "$975.67"));
    table.insert(Product("YTX", "$309.71"));
    table.insert(Product("RLO", "$443.38"));
    table.insert(Product("UUP", "$204.55"));
    table.insert(Product("BLZ", "$960.98"));
    table.insert(Product("IBV", "$163.72"));
    table.insert(Product("MIZ", "$429.23"));
    table.insert(Product("OBP", "$930.96"));
    table.insert(Product("YCH", "$624.67"));
    table.insert(Product("ODI", "$322.58"));
    table.insert(Product("BIT", "$523.74"));
    table.insert(Product("GSL", "$954.79"));
    table.insert(Product("XWJ", "$432.38"));
    table.insert(Product("SYR", "$115.35"));
    table.insert(Product("ZSC", "$572.49"));
    table.insert(Product("ISB", "$513.69"));
    table.insert(Product("JAL", "$585.30"));
    table.insert(Product("ZLD", "$832.32"));
    table.insert(Product("MHQ", "$201.55"));
    table.insert(Product("QPM", "$731.52"));
    table.insert(Product("IQE", "$191.66"));
    table.insert(Product("SHO", "$325.81"));
    table.insert(Product("MSA", "$763.24"));
    table.insert(Product("AAD", "$911.40"));
    table.insert(Product("NPA", "$824.86"));
    table.insert(Product("WNP", "$167.50"));
    table.insert(Product("DJX", "$390.78"));
    table.insert(Product("LFK", "$247.60"));
    table.insert(Product("VID", "$403.85"));
    table.insert(Product("GSY", "$882.75"));
    table.insert(Product("WPK", "$253.16"));
    table.insert(Product("CGB", "$717.22"));
    table.insert(Product("CLU", "$486.99"));
    table.insert(Product("JQW", "$155.68"));
    table.insert(Product("JME", "$842.41"));
    table.insert(Product("YII", "$789.50"));
    table.insert(Product("YCU", "$845.12"));
    table.insert(Product("ODE", "$178.13"));
    table.insert(Product("ZQM", "$489.51"));
    table.insert(Product("UYT", "$815.53"));
    table.insert(Product("ZFH", "$158.35"));
    table.insert(Product("NTD", "$278.88"));
    table.insert(Product("LBA", "$242.50"));
    table.insert(Product("VRB", "$839.82"));
    table.insert(Product("RXZ", "$236.79"));
    table.insert(Product("BZQ", "$467.91"));
    table.insert(Product("QIB", "$186.98"));
    table.insert(Product("WBJ", "$488.99"));
    table.insert(Product("WMN", "$358.11"));
    table.insert(Product("JUL", "$973.30"));
    table.insert(Product("ZMI", "$106.80"));
    table.insert(Product("LZQ", "$226.26"));
    table.insert(Product("PNY", "$675.86"));
    table.insert(Product("JCI", "$640.27"));
    table.insert(Product("KXO", "$161.39"));
    table.insert(Product("MCM", "$198.80"));
    table.insert(Product("YBO", "$190.31"));
    table.insert(Product("KCM", "$891.13"));
    table.insert(Product("CWB", "$889.74"));
    table.insert(Product("TIR", "$699.40"));
    table.insert(Product("ZHP", "$105.49"));
    table.insert(Product("QEP", "$178.75"));
    table.insert(Product("MID", "$568.47"));
    table.insert(Product("GYG", "$338.60"));
    table.insert(Product("BPK", "$541.37"));
    table.insert(Product("SMH", "$836.68"));
    table.insert(Product("FMZ", "$729.57"));
    table.insert(Product("YQO", "$988.81"));
    table.insert(Product("DMD", "$615.71"));
    table.insert(Product("TUC", "$182.68"));
    table.insert(Product("AEJ", "$654.28"));
    table.insert(Product("HBA", "$443.59"));
    table.insert(Product("DTK", "$474.80"));
    table.insert(Product("ZEZ", "$234.92"));
    table.insert(Product("PZM", "$391.58"));
    table.insert(Product("BGU", "$918.12"));
    table.insert(Product("VWL", "$120.60"));
    table.insert(Product("GKX", "$256.14"));
    table.insert(Product("SHV", "$435.34"));
    table.insert(Product("NMI", "$494.82"));
    table.insert(Product("WUN", "$184.45"));
    table.insert(Product("WVB", "$652.14"));
    table.insert(Product("ZXR", "$590.42"));
    table.insert(Product("WZK", "$307.83"));
    table.insert(Product("ADA", "$471.54"));
    table.insert(Product("ANB", "$546.88"));
    table.insert(Product("CNO", "$596.51"));
    table.insert(Product("IPB", "$158.21"));
    table.insert(Product("VAZ", "$496.95"));
    table.insert(Product("VZU", "$441.63"));
    table.insert(Product("AKD", "$310.49"));
    table.insert(Product("XYD", "$579.65"));
    table.insert(Product("BVX", "$790.35"));
    table.insert(Product("KEB", "$985.10"));
    table.insert(Product("NYW", "$500.77"));
    table.insert(Product("IAG", "$557.13"));
    table.insert(Product("MGM", "$108.81"));
    table.insert(Product("KXJ", "$884.90"));
    table.insert(Product("VGA", "$969.22"));
    table.insert(Product("NLT", "$595.79"));
    table.insert(Product("JIH", "$618.54"));
    table.insert(Product("CNU", "$958.49"));
    table.insert(Product("YAN", "$981.90"));
    table.insert(Product("STI", "$603.73"));
    table.insert(Product("EIZ", "$105.71"));
    table.insert(Product("UCP", "$984.54"));
    table.insert(Product("ACM", "$886.51"));
    table.insert(Product("VUQ", "$137.60"));
    table.insert(Product("KBS", "$298.29"));
    table.insert(Product("OXP", "$934.85"));
    table.insert(Product("KLR", "$704.70"));
    table.insert(Product("TQX", "$809.98"));
    table.insert(Product("ZBC", "$940.47"));
    table.insert(Product("UHU", "$768.67"));
    table.insert(Product("EJW", "$240.96"));
    table.insert(Product("GPP", "$543.79"));
    table.insert(Product("XWK", "$478.30"));
    table.insert(Product("YRH", "$300.21"));
    table.insert(Product("EMZ", "$469.11"));
    table.insert(Product("TLC", "$944.64"));
    table.insert(Product("JGQ", "$407.56"));
    table.insert(Product("VUA", "$580.11"));
    table.insert(Product("OYC", "$713.86"));
    table.insert(Product("NTT", "$217.54"));
    table.insert(Product("PTX", "$462.76"));
    table.insert(Product("FTL", "$973.58"));
    table.insert(Product("OGX", "$286.84"));
    table.insert(Product("NNM", "$870.79"));
    table.insert(Product("JQX", "$491.47"));
    table.insert(Product("VEQ", "$673.48"));
    table.insert(Product("VED", "$250.31"));
    table.insert(Product("RGH", "$509.84"));
    table.insert(Product("EZQ", "$747.10"));
    table.insert(Product("OJP", "$375.61"));
    table.insert(Product("PRO", "$135.39"));
    table.insert(Product("GWX", "$152.65"));
    table.insert(Product("OZQ", "$843.31"));
    table.insert(Product("CFP", "$910.37"));
    table.insert(Product("OID", "$665.48"));
    table.insert(Product("HFT", "$265.49"));
    table.insert(Product("QLV", "$496.59"));
    table.insert(Product("ASW", "$345.43"));
    table.insert(Product("UKF", "$793.24"));
    table.insert(Product("UFU", "$477.53"));
    table.insert(Product("MIC", "$655.37"));
    table.insert(Product("AEE", "$573.76"));
    table.insert(Product("CSC", "$190.13"));
    table.insert(Product("DKN", "$719.26"));
    table.insert(Product("ZDL", "$247.94"));
    table.insert(Product("PNA", "$375.92"));
    table.insert(Product("TBY", "$600.76"));
    table.insert(Product("DJR", "$809.23"));
    table.insert(Product("VDX", "$997.61"));
    table.insert(Product("FNO", "$738.19"));
    table.insert(Product("DUI", "$272.62"));
    table.insert(Product("YGE", "$238.72"));
    table.insert(Product("VYJ", "$787.49"));
    table.insert(Product("LSK", "$508.76"));
    table.insert(Product("MHK", "$325.92"));
    table.insert(Product("MYZ", "$241.73"));
    table.insert(Product("HJX", "$707.69"));
    table.insert(Product("QXH", "$179.80"));
    table.insert(Product("JSN", "$761.98"));
    table.insert(Product("PAC", "$441.43"));
    table.insert(Product("TMI", "$384.58"));
    table.insert(Product("JTE", "$268.51"));
    table.insert(Product("OEV", "$497.52"));
    table.insert(Product("AOU", "$990.51"));
    table.insert(Product("IXM", "$357.38"));
    table.insert(Product("HPL", "$915.27"));
    table.insert(Product("XWR", "$356.76"));
    table.insert(Product("KRC", "$370.96"));
    table.insert(Product("TXA", "$568.53"));
    table.insert(Product("WJK", "$547.80"));
    table.insert(Product("UAH", "$227.63"));
    table.insert(Product("GVJ", "$337.39"));
    table.insert(Product("SIC", "$571.71"));
    table.insert(Product("USM", "$758.87"));
    table.insert(Product("IZR", "$802.34"));
    table.insert(Product("SYE", "$848.69"));
    table.insert(Product("KXL", "$907.41"));
    table.insert(Product("VJY", "$610.23"));
    table.insert(Product("MAR", "$823.27"));
    table.insert(Product("KZY", "$521.82"));
    table.insert(Product("MAE", "$182.53"));
    table.insert(Product("PGP", "$208.46"));
    table.insert(Product("HEJ", "$443.89"));
    table.insert(Product("IAT", "$158.43"));
    table.insert(Product("IIQ", "$585.34"));
    table.insert(Product("KBD", "$660.84"));
    table.insert(Product("AQS", "$459.96"));
    table.insert(Product("CES", "$570.43"));
    table.insert(Product("HUD", "$942.39"));
    table.insert(Product("XLQ", "$441.60"));
    table.insert(Product("EUI", "$523.23"));
    table.insert(Product("RVD", "$392.21"));
    table.insert(Product("QZT", "$808.52"));
    table.insert(Product("SXP", "$657.60"));
    table.insert(Product("LHE", "$627.16"));
    table.insert(Product("YNV", "$540.95"));
    table.insert(Product("WGU", "$662.59"));
    table.insert(Product("DVW", "$134.20"));
    table.insert(Product("BFZ", "$933.53"));
    table.insert(Product("ZWO", "$517.84"));
    table.insert(Product("CTE", "$516.31"));
    table.insert(Product("YAK", "$956.11"));
    table.insert(Product("DPB", "$497.62"));
    table.insert(Product("QTG", "$870.12"));
    table.insert(Product("NBG", "$763.56"));
    table.insert(Product("MBJ", "$214.42"));
    table.insert(Product("MUV", "$860.19"));
    table.insert(Product("TLJ", "$368.97"));
    table.insert(Product("ETW", "$168.51"));
    table.insert(Product("OZY", "$450.83"));
    table.insert(Product("UWE", "$114.72"));
    table.insert(Product("YMQ", "$152.38"));
    table.insert(Product("QWN", "$974.27"));
    table.insert(Product("NIE", "$271.77"));
    table.insert(Product("WNT", "$184.44"));
    table.insert(Product("ELG", "$926.44"));
    table.insert(Product("GRP", "$317.81"));
    table.insert(Product("IHR", "$872.85"));
    table.insert(Product("KWI", "$833.59"));
    table.insert(Product("EML", "$532.85"));
    table.insert(Product("ZIE", "$389.22"));
    table.insert(Product("MQJ", "$829.22"));
    table.insert(Product("MKX", "$941.52"));
    table.insert(Product("XIZ", "$697.14"));
    table.insert(Product("KGJ", "$142.57"));
    table.insert(Product("MRI", "$460.24"));
    table.insert(Product("YWQ", "$390.72"));
    table.insert(Product("VAY", "$194.66"));
    table.insert(Product("NLU", "$238.46"));
    table.insert(Product("VVR", "$490.73"));
    table.insert(Product("COH", "$839.37"));
    table.insert(Product("QFQ", "$805.73"));
    table.insert(Product("USO", "$263.79"));
    table.insert(Product("AJI", "$466.37"));
    table.insert(Product("TEH", "$941.74"));
    table.insert(Product("AMZ", "$138.13"));
    table.insert(Product("UMM", "$671.32"));
    table.insert(Product("YDR", "$854.86"));
    table.insert(Product("LXW", "$117.19"));
    table.insert(Product("QMT", "$151.82"));
    table.insert(Product("DPS", "$764.76"));
    table.insert(Product("AYZ", "$822.58"));
    table.insert(Product("AYM", "$490.81"));
    table.insert(Product("QBU", "$276.40"));
    table.insert(Product("HIV", "$620.78"));
    table.insert(Product("JKQ", "$414.91"));
    table.insert(Product("VZR", "$413.17"));
    table.insert(Product("OQV", "$437.83"));
    table.insert(Product("QNR", "$996.52"));
    table.insert(Product("VRZ", "$751.39"));
    table.insert(Product("BWJ", "$898.94"));
    table.insert(Product("LNO", "$794.76"));
    table.insert(Product("KKI", "$662.36"));
    table.insert(Product("UPP", "$805.98"));
    table.insert(Product("NWS", "$415.22"));
    table.insert(Product("UQJ", "$831.35"));
    table.insert(Product("KPA", "$996.18"));
    table.insert(Product("PHN", "$557.36"));
    table.insert(Product("TOZ", "$899.11"));
    table.insert(Product("FVD", "$227.68"));
    table.insert(Product("MUX", "$292.10"));
    table.insert(Product("VFH", "$903.28"));
    table.insert(Product("UID", "$995.91"));
    table.insert(Product("RRO", "$233.95"));
    table.insert(Product("HCW", "$662.75"));
    table.insert(Product("TGP", "$659.26"));
    table.insert(Product("FIP", "$787.81"));
    table.insert(Product("UOE", "$713.94"));
    table.insert(Product("ULQ", "$110.86"));
    table.insert(Product("ITV", "$179.34"));
    table.insert(Product("EHO", "$532.16"));
    table.insert(Product("CRD", "$996.35"));
    table.insert(Product("PJV", "$316.57"));
    table.insert(Product("SNN", "$156.38"));

    // print the report
    table.report();

    return 0;
}




