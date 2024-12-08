#include "Inventory.h"

Inventory::Inventory() {}

Inventory::~Inventory() {}

// ------------------------------------Inventory::doInventory-----------------------------------
// Description
// doInventory: prints data of Movie objects stored in MovieLib
// preconditions: takes a MovieLib item
// postconditions: prints MovieLib contents, makes no changes
// ---------------------------------------------------------------------------------------------
void Inventory::doInventory(const MovieLib &movieLib) const { movieLib.print(); }