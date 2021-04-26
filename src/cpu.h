#ifndef CPU_H
#define CPU_H

/* segment starting addresses */
/* 64 kb blocks */
#define DS_START 0x2000 
#define CS_START 0x3000
#define SS_START 0x5000
#define ES_START 0x7000

/* includes */
#include <stdint.h>
#include "types.h"
#include "cpu_extra.h"

/* cpu */
typedef struct cpu {
   /* registers */
   u16 ax; /* accumulator   */
   u16 bx; /* base index    */
   u16 cx; /* count         */
   u16 dx; /* data          */
   u16 sp; /* stack pointer */
   u16 ip; /* instr pointer */
   u16 bp; /* base pointer  */
   u16 si; /* source index  */
   u16 di; /* destn index   */
   u16 cs; /* code segment  */
   u16 ds; /* data segment  */
   u16 ss; /* stack segment */
   u16 es; /* extra segment */
   u16 flags;
   u8* mem; /* main memory */
} cpu;

/* cpu procs */
void cpu_init(cpu* c);
void cpu_init_segments(cpu *c);
void cpu_set_segments(cpu *c, u16 cs, u16 ds, u16 ss, u16 es);
void cpu_setmem(cpu* c, u8* mem); 
void cpu_exec(cpu* c, u8 instr);
void cpu_dump(cpu* c);
void cpu_dump_mem(cpu* c, u32 start_addr, u32 end_addr);
void cpu_write_u8_at(cpu* c, u32 addr, u8 data);
void cpu_write_u16_at(cpu* c, u32 addr, u16 data);
void set_reg8(cpu* c, reg r, u8 val);
void set_reg16(cpu* c, reg r, u16 val);
void extract_rg_mrm (cpu* c, u8* next, u8* rg, u8* m_rm, u8 regtype);
void get_offset_mrm(cpu* c, u8* next, u8* m_rm, u8* mod, u16* offset);

u8 cpu_read_u8_at(cpu* c, u32 addr);
u8 cpu_fetch(cpu* c);
u8 get_reg8(u8 regnum);
u8 get_reg16(u8 regnum);
u8 get_reg8_val(cpu* c, reg r);
u8 get_sreg16(u8 regnum);
u8 rotate8(u8 val, u8 rby, i8 rl);

u16 switch_bytes(u16 val);
u16 rotate16(u16 val, u8 rby, i8 rl);
u16 get_reg16_val(cpu* c, reg r);
u16 cpu_read_u16_at(cpu* c, u32 addr);
u16 get_base_override(cpu* c, u8 ovr);
u16 get_base_default(cpu* c, reg regs);
u16 get_base_from_mrm(cpu* c, u8 mrm);

u32 base_offset(u16 base, u16 offset);
u32 get_mrm_loc(cpu *c, u8 mrm, u16 base_segment, u16 offset);

void mov_r16i(cpu* c, reg dst, u16 val);
void mov_r8i(cpu* c, reg dst, u8 val);
void mov_r16r(cpu* c, reg dst, reg src);
void mov_r8r(cpu* c, reg dst, reg src);
void mov_rm(cpu* c, reg dst, u32 addr);
void mov_mr(cpu* c, u32 addr, reg src);
void inc_dec_r(cpu* c, reg r, i8 id);
void inc_dec_m(cpu* c, u32 addr, u8 bw, i8 id);
void push_r(cpu *c, reg r);
void pop_r(cpu *c, reg r);
void shift_left_r(cpu* c, reg r, int shift_amount, u8 memsize);
void shift_left_m(cpu* c, u32 addr, int shift_amount, u8 memsize);
void shift_uright_r(cpu* c, reg r, int shift_amount, u8 memsize);
void shift_uright_r(cpu* c, reg r, int shift_amount, u8 memsize);
void shift_iright_r(cpu* c, reg r, int shift_amount, u8 memsize);
void shift_iright_r(cpu* c, reg r, int shift_amount, u8 memsize);
void rotate_left_r(cpu* c, reg r, int rotate_amount, u8 memsize);
void rotate_left_m(cpu* c, u32 addr, int rotate_amount, u8 memsize);
void rotate_right_r(cpu* c, reg r, int rotate_amount, u8 memsize);
void rotate_right_m(cpu* c, u32 addr, int rotate_amount, u8 memsize);

#endif
