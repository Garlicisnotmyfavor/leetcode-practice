class Solution {
public:
    string defangIPaddr(string address) {
        string::size_type pos = 0;
        while ((pos = address.find(".", pos)) != string::npos) {
            address.replace(pos, 1, "[.]");
            pos += 3;
        }
        return address;
    }
};