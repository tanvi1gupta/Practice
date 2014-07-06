#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include <unistd.h>
using namespace std;
bool has_initialized = false;
void *managed_memory_start;
void *last_valid_Address;
struct mem_block
{
    int is_available;
    int size;
};
void malloc_init()
{
    //this will grab the last valid address from the OS..for linux
    last_valid_address = sbrk(0);
    //no memory to manage yet so the start poitner set as the memory address fetched
    managed_memory_start = last_valid_address;
    has_initialized = true;

}

void *malloc(long numbytes)
{
    void *current_location;
    struct mem_block *current_location_mcb;
    void *memory_location;
    if(!has_initialized)
        malloc_init();

    numbytes += sizeof(current_location_mcd);
    memory_location =0;
    current_location = managed_memory_start;
    whie(current_location!=last_valid_address)
    {
        current_location_mdb = (struct mem_block*)current_location;
        if(current_location_mcb->is_available)
        {
            if(current_location_mcb->size >=numbytes)
            {
                //we got a location for the numbytes
                current_location_mcb->is_available=0;//not available
                memory_location = current_location_mcb;
                break;
            }
        }
            current_location = current_location+current_location_mcb->size;
    }
    if(!memory_location)
    {
        sbrk(numbytes);
        memory_location = last_valid_address;
        last_valid_address+=numbyte;
        current_location_mcb->is_available = 0;
        current_location_mcb->size = numbytes;
        current_location_mcb = memory_location;
    }
    //start of the memory allocation will have the memblock struct
    //this will tell us about the size of the memoy, sowhen we want
    //to free we can simply subtract the sie of of struct and get the struct
    memory_location = memory_location+sizeof(struct mem_block);
    return memory_location;
}
void free(void *firstbyte)
{
    struct mem_nlock *mcb;
    mcb = firstbyte - sizeof(struct mem_block);
    mcb->is_available = 1;
    return;
}


int main()
{
    return 0;
}
