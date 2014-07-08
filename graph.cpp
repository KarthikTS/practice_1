#include<iostream>
#include<vector>
#include<map>
#include<stdexcept>
using namespace std;

class graph{

private:
    map< int,vector<int> > adj_list;

public:

    graph(const vector<int> &starts,const vector<int> &ends){
        if(starts.size()!=ends.size())
            throw invalid_argument("input vectors are not of same length");

        for(int i=0;i<starts.size();i++)
        {
            adj_list[starts[i]].push_back(ends[i]);
            adj_list[ends[i]];
        }
    }

    int no_of_outgoing(const int node_id) const{

        return adjacent_nodes(node_id).size();
    }

    const vector<int> &adjacent_nodes(const int node_id) const{

        map< int,vector<int> > :: const_iterator i = adj_list.find(node_id);

        if(i==adj_list.end())
            throw invalid_argument("invalid node_id");

        return i->second;
    }

};

int main()
{

    vector<int> starts;
    starts.push_back(1);
    starts.push_back(1);
    starts.push_back(1);

    starts.push_back(5);
    starts.push_back(5);
    starts.push_back(4);

    vector<int> ends;
    ends.push_back(2);
    ends.push_back(3);
    ends.push_back(4);
    ends.push_back(4);
    ends.push_back(2);
    ends.push_back(2);

    graph g(starts,ends);

    cout << g.no_of_outgoing(1) << '\n';
    cout << g.no_of_outgoing(5) << '\n';
    cout << g.no_of_outgoing(4) << '\n';

    return 0;
}
