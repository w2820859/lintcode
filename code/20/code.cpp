class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        static const std::vector<int> array = {1,2,3,4,5,6};
        const double per_rate = double(1)/6;
        std::unordered_map<int, double>* last_counter = new std::unordered_map<int, double>({{0,1.0}});
        std::unordered_map<int, double>* curr_counter = new std::unordered_map<int, double>();
        vector<pair<int, double>> ret;
        for (int idx = 0; idx < n; ++idx) {
            for (int x : array) {
                for (auto& p : *last_counter) {
                    int sum = x + p.first;
                    double rate = p.second * per_rate;
                    auto iter = curr_counter->find(sum);
                    if (iter == curr_counter->end()) {
                        curr_counter->insert(std::make_pair(sum, rate));
                    } else {
                        iter->second += rate;
                    }
                }
            }
            last_counter->clear();
            swap(last_counter, curr_counter);
        }

        //int sum = 0;
        //for (const auto& item : *last_counter) {
        //    cout << item.first << " " << item.second << std::endl;
        //    sum += item.second;
        //}
        for (const auto& item : *last_counter) {
            ret.push_back(std::make_pair(item.first, item.second));
        }
        std::sort(ret.begin(), ret.end(), [](pair<int, double>& a, pair<int, double>& b) {return a.first < b.first;});
        return ret;
    }
/*
    vector<pair<int, double>> dicesSum(int n) {
        static const std::vector<int> array = {1,2,3,4,5,6};
        std::map<int, int>* last_counter = new std::map<int, int>({{0,1}});
        std::map<int, int>* curr_counter = new std::map<int, int>();
        vector<pair<int, double>> ret;
        for (int idx = 0; idx < n; ++idx) {
            for (int x : array) {
                for (auto& p : *last_counter) {
                    int sum = x + p.first;
                    int cnt = p.second;
                    auto iter = curr_counter->find(sum);
                    if (iter == curr_counter->end()) {
                        curr_counter->insert(std::make_pair(sum, 1));
                    } else {
                        iter->second += cnt;
                    }
                }
            }
            last_counter->clear();
            swap(last_counter, curr_counter);
        }

        int sum = 0;
        for (const auto& item : *last_counter) {
            sum += item.second;
        }
        for (const auto& item : *last_counter) {
            ret.push_back(std::make_pair(item.first, double(item.second)/sum));
        }
        return ret;
    }
*/
};
