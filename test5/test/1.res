@0   lineno:2   Program children: @1 @5 @8 @11 @14 @19 
@1   lineno:2   StmtType:declare           children: @2 @3 @4 
@2   lineno:2   TYPE:int         
@3   lineno:2   VarType:int   VarName:a          
@4   lineno:2   VarType:int   VarName:s          
@5   lineno:3   Operator:=   children: @6 @7 
@6   lineno:3   VarType:int   VarName:a          
@7   lineno:3   CONST:Interger   value:10    
@8   lineno:4   Operator:=   children: @9 @10 
@9   lineno:4   VarType:int   VarName:s          
@10  lineno:4   CONST:Interger   value:0     
@11  lineno:5   StmtType:declare           children: @12 @13 
@12  lineno:5   TYPE:char        
@13  lineno:5   VarType:int   VarName:ch         
@14  lineno:6   StmtType:scanf             children: @15 
@15  lineno:6   Operator:,   children: @16 @17 
@16  lineno:6   CONST:ConstString value:      
@17  lineno:6   Operator:&   children: @18 
@18  lineno:6   VarType:int   VarName:ch         
@19  lineno:7   StmtType:while             children: @20 @38 @41 @44 @47 @50 
@20  lineno:7   Operator:||  children: @21 @28 
@21  lineno:7   Operator:&&  children: @22 @25 
@22  lineno:7   Operator:>   children: @23 @24 
@23  lineno:7   VarType:int   VarName:a          
@24  lineno:7   CONST:Interger   value:0     
@25  lineno:7   Operator:<=  children: @26 @27 
@26  lineno:7   VarType:int   VarName:a          
@27  lineno:7   CONST:Interger   value:10    
@28  lineno:7   Operator:&&  children: @29 @34 
@29  lineno:7   Operator:==  children: @30 @33 
@30  lineno:7   Operator:%   children: @31 @32 
@31  lineno:7   VarType:int   VarName:a          
@32  lineno:7   CONST:Interger   value:100   
@33  lineno:7   CONST:Interger   value:10    
@34  lineno:7   Operator:!   children: @35 
@35  lineno:7   Operator:==  children: @36 @37 
@36  lineno:7   VarType:int   VarName:a          
@37  lineno:7   CONST:Interger   value:10    
@38  lineno:8   Operator:-=  children: @39 @40 
@39  lineno:8   VarType:int   VarName:a          
@40  lineno:8   CONST:Interger   value:1     
@41  lineno:9   StmtType:declare           children: @42 @43 
@42  lineno:9   TYPE:int         
@43  lineno:9   VarType:int   VarName:a          
@44  lineno:10  Operator:=   children: @45 @46 
@45  lineno:10  VarType:int   VarName:a          
@46  lineno:10  CONST:Interger   value:10    
@47  lineno:11  Operator:+=  children: @48 @49 
@48  lineno:11  VarType:int   VarName:s          
@49  lineno:11  VarType:int   VarName:a          
@50  lineno:12  StmtType:if                children: @51 @56 @60 @63 @66 
@51  lineno:12  Operator:<   children: @52 @54 
@52  lineno:12  Operator:-   children: @53 
@53  lineno:12  VarType:int   VarName:s          
@54  lineno:12  Operator:-   children: @55 
@55  lineno:12  CONST:Interger   value:10    
@56  lineno:13  StmtType:printf            children: @57 
@57  lineno:13  Operator:,   children: @58 @59 
@58  lineno:13  CONST:ConstString value:      
@59  lineno:13  VarType:int   VarName:s          
@60  lineno:14  StmtType:declare           children: @61 @62 
@61  lineno:14  TYPE:int         
@62  lineno:14  VarType:int   VarName:b          
@63  lineno:15  Operator:=   children: @64 @65 
@64  lineno:15  VarType:int   VarName:b          
@65  lineno:15  CONST:Interger   value:10    
@66  lineno:16  StmtType:for               children: @67 @78 
@67  lineno:16  StmtType:condition         children: @68 @73 @76 
@68  lineno:16  StmtType:declare           children: @69 @70 
@69  lineno:16  TYPE:int         
@70  lineno:16  Operator:=   children: @71 @72 
@71  lineno:16  VarType:int   VarName:i          
@72  lineno:16  CONST:Interger   value:0     
@73  lineno:16  Operator:<   children: @74 @75 
@74  lineno:16  VarType:int   VarName:i          
@75  lineno:16  VarType:int   VarName:b          
@76  lineno:16  Operator:++  children: @77 
@77  lineno:16  VarType:int   VarName:i          
@78  lineno:17  StmtType:printf            children: @79 
@79  lineno:17  Operator:,   children: @80 @81 
@80  lineno:17  CONST:ConstString value:      
@81  lineno:17  VarType:int   VarName:i          
