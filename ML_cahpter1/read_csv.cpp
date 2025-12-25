#include <iostream>
#include "external/csv.h"

const uint32_t columns_num = 3;
using RowType = std::tuple<std::string, std::string, std::string>;
RowType row;

template <std::size_t... Idx, typename T, typename R>
bool read_row_help(std::index_sequence<Idx...>, T &tuple, R &reader){
    return reader.read_row(std::get<Idx>(tuple)...);
}

template <std::size_t... Idx, typename T>
void fill_values(std::index_sequence<Idx...>, T& row, std::vector<std::string>& data){
    data.insert(data.end(), {std::get<Idx>(row)...});
}

int main(){
    io::CSVReader<columns_num> csv_reader("../day.csv");

    std::vector<std::string> categorical_column;
    std::vector<std::string> values;


    try {
        bool done = false;
        while (!done) {
            done = !read_row_help(
            std::make_index_sequence<std::tuple_size<RowType>::value>{}, row, csv_reader);
            if (!done) {
                categorical_column.push_back(std::get<0>(row));
                fill_values(std::make_index_sequence<columns_num-1>{}, row, values);
            }
        }
        } catch (const io::error::no_digit& err) {
            // ignore badly formatted samples
            std::cerr << err.what() << std::endl;
    }


    return 0;
}