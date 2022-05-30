#indef CYOL_BINDER_H
#define CYOL_BINDER_H
#include "visitor.h"
#include <stdint.h>

typedef struct Dataframe {
	uint8_t *id;
	uint8_t type;
	uint32_t addr; 
    
    struct Dataframe *prev;




} Datafram;
typedef struct Stackframe {
	Dataframe *df; 
	struct Dataframe *prev; }
	Stackframe; 

Stackframe *bind (AST *ast);
void display_frame(Stackframe *sf);
Stackframe *new_stackframe();
Dataframe *newdataframe(uint8_t *id, uint8_t type, uint32_t addr);
void open_frame(Stackframe **sf);
Dataframe *find_data(Stackframe *sf,uint8_t *id); // au niveau de la decaration, on verifie si la varibale existe localement
Dataframe *findall_data(Stackframe *sf,uint8_t *id); // global
void put_data(Stackframe **sf,uint8_t *id,uint8_t type,uint32_t addr);





#endif // CYOL_BINDER   
