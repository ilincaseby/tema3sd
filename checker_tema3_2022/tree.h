#ifndef TREE_H
#define TREE_H

#define TREE_CMD_INDENT_SIZE 4
#define NO_ARG ""
#define PARENT_DIR ".."

typedef struct File_content File_content;
typedef struct Folder_content Folder_content;
typedef struct Tree_node Tree_node;
typedef struct File_tree File_tree;
typedef struct List List;

enum Tree_nodeType {
    FILE_NODE,
    FOLDER_NODE
};

struct File_content {
    char* text;
};

struct Folder_content {
    List* children;
};

struct Tree_node {
    Tree_node* parent;
    char* name;
    enum Tree_nodeType type;
    void* content;
};

struct File_tree {
    Tree_node* root;
};

/* Replicates the function `strdup`. */
char* my_strdup(char* str);

/* Creates a Tree_node* with name `treeNodeName`. */
Tree_node* tree_node_create(char* treeNodeName);

/* Creates a File_tree with root `rootFolderName`. */
File_tree file_tree_create(char* rootFolderName);

/* Frees the memory allocated for a Tree_node. */
void tree_node_free(Tree_node* treeNode);

/* Frees the memory allocated for a File_tree. */
void tree_free(File_tree fileTree);

/* Adds a file with name `fileName` and content `fileContent` to the current
directory. */
void touch(Tree_node* currentNode, char* fileName, char* fileContent);

/* Lists the contents of the specified directory or file. */
void ls(Tree_node* currentNode, char* arg);

/* Creates a new directory with name `folderName` at the current path. */
void mkdir(Tree_node* currentNode, char* folderName);

/* Changes the current path to a given path. */
Tree_node* cd(Tree_node* currentNode, char* path);

/* Prints the hierarchy starting from the path given by `arg`. Shows the number
of directories and files in the hierarchy. */
void tree(Tree_node* currentNode, char* arg);

/* Prints the absolute path to the current working directory. */
void pwd(Tree_node* treeNode);

/* Removes an empty directory. */
void rmdir(Tree_node* currentNode, char* folderName);

/* Deletes a file contained by the current directory. */
void rm(Tree_node* currentNode, char* fileName);

/* Removes a file or a directory, along with its contents. */
void rmrec(Tree_node* currentNode, char* resourceName);

/* Copies a file from the source path to the destination path. */
void cp(Tree_node* currentNode, char* source, char* destination);

/* Moves a file or directory from the source path to the destination path. */
void mv(Tree_node* currentNode, char* source, char* destination);

#endif  // TREE_H
