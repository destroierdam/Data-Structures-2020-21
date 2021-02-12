#include <iostream>
#include <queue>
#include <vector>

const size_t ROWS = 4, COLS = 5;

char kasetka[ROWS][COLS] = { { 'b', 'g', 'x', 'x', 'g'},
                             { 'g', 'x', 'g', 'x', 'x'},
                             { 'g', 'x', 'g', 'b', 'x'},
                             { 'g', 'g', 'g', 'g', 'x'} };

struct Pos {
    unsigned int row;
    unsigned int col;
    Pos(unsigned int row, unsigned int col):row(row), col(col){}

    Pos make_left() const {
        return {this->row, this->col - 1};
    }
    Pos make_right() const {
        return {this->row, this->col + 1};
    }
    Pos make_up() const {
        return {this->row - 1, this->col};
    }
    Pos make_down() const {
        return {this->row + 1, this->col};
    }


    bool isValid() const {
        return row < ROWS && col < COLS;
    }

    bool operator==(const Pos& other) {
        return this->row == other.row && this->col == other.col;
    }
};

std::vector<Pos> make_valid_neighbors(Pos current) {
    std::vector<Pos> neighbors;

    if(current.make_left().isValid()) {
        neighbors.push_back(current.make_left());
    }
    if(current.make_right().isValid() ) {
        neighbors.push_back(current.make_right());
    }
    if(current.make_up().isValid()) {
        neighbors.push_back(current.make_up());
    }
    if(current.make_down().isValid()) {
        neighbors.push_back(current.make_down());
    }
    return neighbors;
}


int timeToRotAllOranges() {
    std::queue<Pos> q;
    int time = 0;

    for(size_t i = 0; i < ROWS; i++) {
        for(size_t j = 0; j < COLS; j++) {
            if(kasetka[i][j] == 'b') {
                q.push(Pos(i, j));
            }
        }
    }

    Pos delimiter{ROWS, COLS};
    q.push(delimiter);

    while(q.empty() == false) {
        Pos current = q.front();
        q.pop();

        if (current == delimiter) {            
            // Ako ima oshte portokali koito chakat
            if(q.empty() == false) {
                q.push(delimiter);
                ++time;
            }
        }

        const std::vector<Pos> neighbors = make_valid_neighbors(current);

        for (auto & neighbor : neighbors) {
            char & newRotten = kasetka[neighbor.row][neighbor.col];
            
            if(newRotten == 'g') {
                q.push(neighbor);
                newRotten = 'b';
            }
        }
    }

    for(size_t i = 0; i < ROWS; i++) {
        for(size_t j = 0; j < COLS; j++) {
            if(kasetka[i][j] == 'g') {
                return -1;
            }
        }
    }

    return time;
}

int main() {
    std::cout << timeToRotAllOranges() << std::endl;
    return 0;
}