#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Main_Decoder
int8_t  ImmSrc = 0;
uint8_t MemWrite = 0;
uint8_t RegWrite = 0;
uint8_t ALUOp = 0;
uint8_t ALUSrc = 0;
uint8_t ResultSrc = 0;

//PC IO
uint32_t PCNext = 0;    //IN
uint32_t PC = 0;        //OUT
uint32_t PCPlus4 =0;

//Instr_Memory IO
uint32_t Instr_Memory[10] = {0xFFC4A303, 0x0064A423, 0x0062E233, 0xff5ff0ef, 0, 0, 0, 0, 0}; //0xFE420AE3
uint32_t Instr_Memory_A  = 0;    //IN
uint32_t Instr_Memory_RD = 0;    //OUT

/*******************
We changed the order of the instructions to test out both jal & jalr instructions
lw x6, -4(x9)
jal x8, L7
L7: sw x6, 8(x9)
or x4, x5, x6
jalr x0, x8, 0
beq x4, x4, L7
*******************/

//Instr_Memory IO
uint32_t Instr = 0;
uint32_t Instr_19_15 = 0;
//uint32_t Instr_31_20 = 0;
uint32_t Instr_11_7  = 0;
uint32_t Instr_24_20  = 0;
uint32_t Instr_6_0  = 0;


//Register File IO
uint32_t X[32];               //Registers
uint8_t  Reg_File_A1  = 0;    //IN
uint8_t  Reg_File_A2  = 0;    //IN
uint8_t  Reg_File_A3  = 0;    //IN
uint32_t Reg_File_RD1 = 0;    //OUT
uint32_t Reg_File_RD2 = 0;    //OUT
uint32_t Reg_File_WD3 = 0;    //IN
uint8_t  Reg_File_EW3 = 0;    //IN

//Extend IO
int32_t ImmExt      = 0;
uint32_t PCTarget   = 0;
uint8_t PCSrc       = 0;
uint8_t branch      = 0;
uint8_t jump        = 0;

// ALU
int32_t srA = 0;
int32_t srB = 0;
int32_t ALUResult = 0;
uint8_t ALUControl2 = 0;
uint8_t zero;


//Data_Memory IO
uint32_t Data_Memory[0xFFFF];
uint32_t Data_Memory_A  = 0;    //IN
uint32_t Data_Memory_RD = 0;    //OUT
uint32_t Data_Memory_WD = 0;
uint8_t  Data_Memory_WE = 0;



void Data_Memory_Prosses(void);
void Data_Memory_CLK(void);

void Register_File_Prosses(void);
void Register_File_CLK(void);

void PC_CLK(void);

void ALU_Prosses(void);
void Extend_Prosses(void);
void Instr_Memory_Prosses(void);

void Print_Instr_Memory(void);
void Print_Register_File(void);
uint32_t Get_Bits(uint32_t data,uint8_t b1,uint8_t b2);


void Main_Decoder_Prosses (void)
{
        printf("\n\rMain_Decoder_Prosses *****\n\r");
        switch( Instr_6_0 )
        {
            case 3: // lw
                printf("Main_Decoder_Prosses lw\n\r");
                ImmSrc = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUOp = 0;
                ALUSrc = 1;
                ResultSrc = 1;
                branch = 0;
                jump = 0;

                break;
            case 35: // sw
                printf("Main_Decoder_Prosses sw\n\r");
                ImmSrc = 1;
                MemWrite = 1;
                RegWrite = 0;
                ALUOp = 0;
                ALUSrc = 1;
                branch = 0;
                ResultSrc = 0;
                jump = 0;

                break;
            case 51: //R-type
                printf("Main_Decoder_Prosses R-type\n\r");
                ImmSrc = 0;
                MemWrite = 0;
                RegWrite = 1;
                ALUOp = 2;
                ALUSrc = 0;
                branch = 0;
                ResultSrc = 0;
                jump = 0;

                break;
            case 99: // beq
                printf("Main_Decoder_Prosses beq\n\r");
                ImmSrc = 2;
                MemWrite = 0;
                RegWrite = 0;
                ALUOp = 1;
                ALUSrc = 0;
                branch = 1;
                ResultSrc = 0;
                jump = 0;

                break;
            case 19: // I-Type
                printf("Main_Decoder_Prosses I-Type\n\r");
                ImmSrc = 00;
                MemWrite = 0;
                RegWrite = 1;
                ALUOp = 2;
                ALUSrc = 1;
                branch = 0;
                ResultSrc = 0;
                jump = 0;

                break;
            case 111: // Jal
                printf("Main_Decoder_Prosses Jal\n\r");
                ImmSrc = 3;
                MemWrite = 0;
                RegWrite = 1;
                ALUOp = 0;
                ALUSrc = 0;
                branch = 0;
                ResultSrc = 2;
                jump = 1;

                break;

            default:
                ImmSrc = 0;
                MemWrite = 0;
                RegWrite = 0;
                ALUOp = 0;
                ALUSrc = 0;
                branch = 0;
                ResultSrc = 0;
                jump = 0;

        }

        printf("Main_Decoder_Prosses ImmSrc         = %d\n\r",ImmSrc);
        printf("Main_Decoder_Prosses MemWrite       = %d\n\r",MemWrite);
        printf("Main_Decoder_Prosses RegWrite       = %d\n\r",RegWrite);
        printf("Main_Decoder_Prosses ALUOp          = %d\n\r",ALUOp);
        printf("Main_Decoder_Prosses ALUSrc         = %d\n\r",ALUSrc);
        printf("Main_Decoder_Prosses ResultSrc      = %d\n\r",ResultSrc);
        printf("Main_Decoder_Prosses branch         = %d\n\r",branch);
        printf("Main_Decoder_Prosses jump           = %d\n\r",jump);
    }

void Extend_Prosses(void)
{
    printf("\n\rExtend_Prosses *****\n\r");

    uint32_t Data = 0;
    /************************************************/
    //These are then ImmExt for the B-Type command:

    uint32_t Data_11 = Get_Bits(Instr,7,7); //a label can only be part of a statement and a
                                        //declaration is not a statement|
    uint32_t Data_4_1 = Get_Bits(Instr,11,8);
    uint32_t Data_10_5 = Get_Bits(Instr,30,25);
    uint32_t Data_12 = Get_Bits(Instr,31,31);
    /************************************************/
    //These are then ImmExt for the J-Type command:

     uint32_t Data_11_J = Get_Bits(Instr,20,20); 
     uint32_t Data_10_1 = Get_Bits(Instr,30,21); 
     uint32_t Data_19_12 = Get_Bits(Instr,19,12);
     uint32_t Data_20 = Get_Bits(Instr,31,31);
     // Here we do not include the bit 0 since it is granted, similar to the B-type.
    /************************************************/
    switch(ImmSrc)
    {
        case 0:
            Data = Get_Bits(Instr,31,20);
            break;
        case 1:
            Data = Get_Bits(Instr,31,24);
            Data = Data << 5;
            Data = Data + Get_Bits(Instr,11,7);
            break;
        case 2:
            //Data_12 = 1;
            Data = (Data_12 << 11) + (Data_11 << 10) + (Data_10_5 << 4) + (Data_4_1);
            Data = Data << 1;
            printf("########Extend_Prosses Data      = %d\n\r",Data);
            //_12 _11 10 9 8 7 6 5 4 3 2 1 0
            break;
        case 3:
            Data = (Data_20 << 19) + (Data_19_12 << 18) + (Data_11_J << 10) + (Data_10_1);
            Data = Data << 1;
            printf("########Extend_Prosses Data_3      = %d\n\r",Data);
            // _20 _19 18 17 16 15 14 13 _12 _11 10 9 8 7 6 5 4 3 2 1 _0
            break;
        default:
            Data = 0;
    }

    uint32_t bit12 = Get_Bits(Data,11,11);

    if(bit12 == 1)
    {
        Data = 0xFFFFF000 | Data;
    }
    ImmExt = Data;

    //printf("bit12  = %d \n\r",bit12);
    printf("ImmExt = 0x%08x (%d)\n\r",ImmExt, ImmExt);
}

void ALU_Decoder_Prosses()
{
    printf("\n\r ALU_Decoder_Prosses *****\n\r");
    uint8_t _funct3 = Get_Bits(Instr,14,12);
    uint8_t _funct7 = Get_Bits(Instr,31,25);
    uint8_t _op     = Get_Bits(Instr,6,0);
    uint8_t _op_5   = Get_Bits(_op,4,4);
    uint8_t _funct7_5   = Get_Bits(_funct7,4,4);
    uint8_t _op_5_funct7_5 = (_op_5 << 1) + _funct7_5;

    switch(ALUOp)
        {
            case 0:
                printf("ALU_Decoder_Prosses ALUOp = 0\n\r");
                ALUControl2 = 0;
                break;
            case 1:
                printf("ALU_Decoder_Prosses ALUOp = 1\n\r");
                ALUControl2 = 1;
                break;
            case 2:
                printf("ALU_Decoder_Prosses ALUOp = 2\n\r");

                switch(_funct3)
                {
                    case 0:
                        printf("ALU_Decoder_Prosses _funct3 = 0\n\r");
                        switch(_op_5_funct7_5)
                        {
                            case 0:
                            case 1:
                            case 2:
                                break;
                            case 3:
                                break;
                            default:
                                break;

                        }
                    case 2:
                        printf("ALU_Decoder_Prosses _funct3 = 2\n\r");

                        break;
                    case 6:
                        printf("ALU_Decoder_Prosses _funct3 = 6\n\r");
                        ALUControl2 = 3;

                        break;
                    case 7:
                        printf("_Decoder_Prosses _funct3 = 7\n\r");

                        break;
                    default:
                        printf("ALU_Decoder_Prosses _funct3 = ERROR\n\r");

                        break;
                }
                break;

            default:
                printf("ALU_Decoder_Prosses ERROR\n\r");
                break;
        }
        printf("ALU_Decoder_Prosses ALUControl2 = %d\n\r",ALUControl2);
}

int main()
{
    //------------------------------------------
    printf("RISC-V RV32I SOFT CORE\n\r");
    Print_Instr_Memory();
    //-------------------------------------------
    printf("Clean Register File\n\r");
    for (uint32_t i = 0; i < 32; i++) X[i]=0;
    //-----------------------------------------
    X[5] = 6;
    X[9] = 0x2004;
    Data_Memory[0x2000]= 10;
    //-------------------------------------------
    Print_Register_File();
    //-------------------------------------------
    for (uint32_t i = 0; i < 9; i++)
    {
        printf("---------------------------------------------------------------------\n\r");
        printf("PC: 0x%08x\n\r",PC);
    //----------------------
        Instr_Memory_Prosses();
    //----------------------
        Instr       = Instr_Memory_RD;
        Instr_19_15 = Get_Bits(Instr,19,15); // A1
        //Instr_31_20 = Get_Bits(Instr,31,20); // Extend
        Instr_11_7  = Get_Bits(Instr,11,7);  // A3
        Instr_24_20 = Get_Bits(Instr,24,20); // A2
        Instr_6_0   = Get_Bits(Instr,6,0); // A2

    //----------------------
        Main_Decoder_Prosses();
    //----------------------
        ALU_Decoder_Prosses();
    //----------------------
        Register_File_Prosses();
    //----------------------
        Extend_Prosses();
    //----------------------
        PCTarget = ImmExt + PC;
        printf("###############PCTarget: 0x%08x\n\r",PCTarget);

    //----------------------
        if(ALUSrc == 0)
        {
            srB = Reg_File_RD2;
        }
        else{
            srB = ImmExt;
        }
    //----------------------

        srA = Reg_File_RD1;
        //ALUControl2 = 0;
        ALU_Prosses();
    //----------------------
        PCSrc = ((zero & branch) || jump);
        printf("##########PCSrc          = %d\n\r",PCSrc);
    //----------------------
        Data_Memory_A = ALUResult;

        Data_Memory_WD = Reg_File_RD2;//
        Data_Memory_WE = MemWrite;

        Data_Memory_Prosses();
    //----------------------
        if(ResultSrc == 0)
        {
            Reg_File_WD3 = ALUResult;
        }
        else if (ResultSrc == 1){
            Reg_File_WD3 = Data_Memory_RD;
        }
        else if (ResultSrc == 2){
            Reg_File_WD3 = PCPlus4;
        }
    //----------------------
        //Reg_File_WD3 = Data_Memory_RD;
        Reg_File_EW3 = RegWrite;
    //----------------------

         PCPlus4 = PC + 4;
         if(PCSrc == 1)
         {
             PCNext = PCTarget;
         }
         else{
             PCNext = PCPlus4;
         }
        printf("###############PCNext: 0x%08x\n\r",PCNext);

    //----------------------

    //    the CLK waiting area

    //----------------------
        Register_File_CLK();
        Data_Memory_CLK();
        PC_CLK();
    }
    return 0;
}

void Print_Instr_Memory(void)
{
    printf("\n\rInstruction Memory Content: \n\r");
    for (uint32_t i = 0; i < 10; i++)
    {
        printf("Address: 0x%08x value: 0x%08x\n\r",i,Instr_Memory[i]);
    }
    printf("\n\r");
}


void Data_Memory_CLK(void)
{
    printf("\n\rData_Memory_CLK *****\n\r",Data_Memory_A);
    if(Data_Memory_WE==1)
    {
        Data_Memory[Data_Memory_A]=Data_Memory_WD;
        printf("Address: 0x%08x value: 0x%08x\n\r",Data_Memory_A, Data_Memory[Data_Memory_A]);
    }
}



void PC_CLK(void)
{
    printf("\n\rPC_CLK *****\n\r",Data_Memory_A);
    PC = PCNext;
    printf("PC = 0x%08x\n\r",PCNext);
}
void Register_File_CLK(void)
{
    printf("\n\rRegister_File_CLK *****\n\r",Reg_File_EW3);
    printf("Register_File EW3 = %d\n\r",Reg_File_EW3);
    printf("Register_File  A3 = %d\n\r",Reg_File_A3);
    printf("Register_File WD3 = %d\n\r",Reg_File_WD3);
    if(Reg_File_EW3==1)
    {
        X[Reg_File_A3] = Reg_File_WD3 ;
        Print_Register_File();
    }
}


void Data_Memory_Prosses(void)
{
    printf("\n\rData_Memory_Prosses *****\n\r",Data_Memory_A);
    printf("Data_Memory  A = 0x%x\n\r",Data_Memory_A);
    Data_Memory_RD = Data_Memory[Data_Memory_A];
    printf("Data_Memory RD = 0x%x (%d)\n\r",Data_Memory_RD,Data_Memory_RD);
}


void ALU_Prosses()
{
    printf("\n\rALU_Prosses *****\n\r");
    switch( ALUControl2 )
    {
        case 0:
            ALUResult = srA + srB;
            break;
        case 1:
            ALUResult = srA - srB;
            break;
        case 3:
            ALUResult = srA | srB;
            break;
        default:
            ALUResult = 0;
    }
    if(ALUResult == 0)
    {
        zero = 1;
    }
    else{
        zero = 0;

    }
    printf("srA         = 0x%x\n\r",srA);
    printf("srB         = 0x%x\n\r",srB);
    printf("ALUControl2 = 0x%x\n\r",ALUControl2);
    printf("ALUResult   = 0x%x(%d)\n\r",ALUResult,ALUResult);
    printf("zero        = 0x%x\n\r",zero);

}


void Register_File_Prosses(void)
{
    printf("\n\rRegister_File_Prosses *****\n\r");
    printf("Register_File  A1 = %d \n\r",Instr_19_15);
    Reg_File_RD1 = X[Instr_19_15];
    Reg_File_RD2 = X[Instr_24_20];
    printf("Register_File RD1 = 0x%x\n\r",Reg_File_RD1);
    printf("Register_File RD2 = 0x%x\n\r",Reg_File_RD2);

    Reg_File_A3 = Instr_11_7;
    printf("Register_File  A3 = %d \n\r",Reg_File_A3);
}



uint32_t Get_Bits(uint32_t data,uint8_t b1,uint8_t b2)
{
    uint8_t bc = (b1+1)-b2;
    uint32_t b_mask = 0;
    for (uint8_t i = 0; i < bc; i++)
    {
        b_mask += 1 << (b2 + i);
    }
    data = (data & b_mask)>>b2;
    printf("BITS[%d:%d] IS = 0x%x \n\r",b1,b2,data);
    return data;
}

void Instr_Memory_Prosses(void)
{
    printf("\n\rInstr_Memory_Prosses *****\n\r");
    Instr_Memory_A  = PC >> 2;
    Instr_Memory_RD = Instr_Memory[Instr_Memory_A];
    printf("Instr_Memory_RD 0x%08x\n\r",Instr_Memory_RD);
}



void Print_Register_File(void)
{
    printf("\n\rRegister_File Content: \n\r");
    uint32_t A,B,C,D;
    for (uint32_t I = 0; I < 8; I++)
    {
        A = I; B = 8+I; C = 16+I; D = 24+I;
        printf("X[%d] 0x%08x   X[%d] 0x%08x   X[%d] 0x%08x   X[%d] 0x%08x\n\r",A,X[A],B,X[B],C,X[C],D,X[D]);
    }
    printf("\n\r");
}
