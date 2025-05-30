#include <bits/stdc++.h>
using namespace std;


struct InputBuffer {
    string buffer;
    size_t buffer_length;
    ssize_t input_length;
    
};

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND,
} MetaStatus;
typedef enum {
    STATEMENT_SELECT,
    STATEMENT_INSERT,
    STATEMENT_UPDATE,
    STATEMENT_DELETE,
} StatementType;
typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
} PrepareStatus;

typedef struct {
  StatementType type;
} Statement;

InputBuffer new_buffer() {
    InputBuffer input_buffer;
    input_buffer.buffer = "";
    input_buffer.buffer_length = 0;
    input_buffer.input_length = 0;
    return input_buffer;
}



void readInput(InputBuffer &input_buffer) {
    cout << "db > " << flush;
    getline(cin, input_buffer.buffer);
    input_buffer.input_length = input_buffer.buffer.size();
    input_buffer.buffer_length = input_buffer.input_length;
    if (input_buffer.buffer_length <= 0) {
        cout << "Input buffer is empty." << endl;
        exit(EXIT_FAILURE);
    }
}
void free_buffer(InputBuffer &input_buffer) {
    delete &input_buffer;
}

MetaStatus do_meta_command(InputBuffer input_buffer) {
  if (input_buffer.buffer == ".exit") {
    free_buffer(input_buffer);
    return META_COMMAND_SUCCESS;
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}

PrepareStatus prepare_statement(Statement &statement, InputBuffer &input_buffer) {
    string input = input_buffer.buffer;
    if (input.substr(0, 6) == "insert") {
        statement.type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    } else if (input.substr(0, 6) == "select") {
        statement.type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    } else if (input.substr(0, 6) == "update") {
        statement.type = STATEMENT_UPDATE;
        return PREPARE_SUCCESS;
    } else if (input.substr(0, 6) == "delete") {
        statement.type = STATEMENT_DELETE;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void insert() {
    cout << "Inserting data..." << endl;
}

void select() {
    cout << "Selecting data..." << endl;
}

void update() {
    cout << "Updating data..." << endl;
}

void delete_data() {
    cout << "Deleting data..." << endl;
}


void execute_statement(Statement &statement) {
    switch (statement.type) {
        case STATEMENT_INSERT:
            cout << "Executing INSERT statement." << endl;
            insert();
            break;
        case STATEMENT_SELECT:
            cout << "Executing SELECT statement." << endl;
            select();
            break;
        case STATEMENT_UPDATE:
            cout << "Executing UPDATE statement." << endl;
            update();
            break;
        case STATEMENT_DELETE:
            cout << "Executing DELETE statement." << endl;
            delete_data();
            break;
        default:
            cout << "Unknown statement type." << endl;
    }
}



int main() {
    InputBuffer input_buffer = new_buffer();
    while (true) {
        readInput(input_buffer);
        if (input_buffer.buffer == ". exit") {
            cout << "Exiting..." << endl;
            return 0;
        } else {
            cout << "Unknown command: " << input_buffer.buffer << endl;
        }
        free_buffer(input_buffer);
    }
    return 0;
}

