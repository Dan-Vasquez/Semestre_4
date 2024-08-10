import instrucciones1
import registros1

codigo = "assembly_code.txt"

codigo_bin = ""

instrucciones_opcode = instrucciones1.ins_opcode
instrucciones = instrucciones1.ins

registros = registros1.reg
registros_bin = registros1.reg_bin

with open(codigo) as cod:
    lineas = cod.readlines()

def calcular_registro(linea):
    bin = ""
    linea_lit = linea.split(" ")
    for i in range(len(linea_lit)):
        for k in range(len(registros)):
            if registros[k] in linea_lit[i]:
                bin += " " + registros_bin[registros[k]]
    return bin

def separar_16(cadena):
    bandera = -1
    nueva_cadena = " "
    for i in range(len(cadena)):
        if bandera == 3:
            nueva_cadena += " " + cadena[i]
            bandera = 0
        else:
            nueva_cadena += cadena[i]
            bandera += 1
    return nueva_cadena


def calcular_hexa(linea):
    bin = ""
    bandera = 0
    if "0x" in linea:
        l = linea.index("0x") + 2
        while (linea[l] != " "):
            if linea[l] == "A" or linea[l] == "a":
                bin += " " + str(format(10, "04b"))
                bandera += 1
            elif linea[l] == "B" or linea[l] == "b":
                bin += " " + str(format(11, "04b"))
                bandera += 1
            elif linea[l] == "C" or linea[l] == "c":
                bin += " " + str(format(12, "04b"))
                bandera += 1
            elif linea[l] == "D" or linea[l] == "d":
                bin += " " + str(format(13, "04b"))
                bandera += 1
            elif linea[l] == "E" or linea[l] == "e":
                bin += " " + str(format(14, "04b"))
                bandera += 1
            elif linea[l] == "F" or linea[l] == "f":
                bin += " " + str(format(15, "04b"))
                bandera += 1
            else:
                bin += " " + str(format(int(linea[l]), "04b"))
                bandera += 1
            l += 1
    if bandera == 1:
        bin = " 0000 0000 0000" + bin
    elif bandera == 2:
        bin = " 0000 0000" + bin
    elif bandera == 3:
        bin = " 0000" + bin
    return bin

numeros = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
lui = ""
ori = ""
Hi = ""
Lo = ""
direcciones = {0: "0x00401000"}
dir_etiquetas = {}
dir_etiquetas_resultados = {}
dir_suma = 4198400
bandera_ori_lui = 0
o = 0

for o in range(len(lineas)):
    dir_suma += 4
    dir_hex = "0x" + str(format(dir_suma, "08x"))
    direcciones[o + 1] = dir_hex

for i in range(len(lineas)):
    linea = lineas[i]
    linea_lit = linea.split(" ")
    if linea_lit[0] + " " not in instrucciones:
        dir_etiquetas[linea_lit[0][:-1]] = direcciones[i]

for i in range(len(lineas)):
    linea = lineas[i]
    code = ""
    linea_lit = linea.split(" ")

    for j in range(len(instrucciones)):
        if (instrucciones[j] == linea_lit[0] + " "):
            code += instrucciones_opcode[instrucciones[j]][2]
            if instrucciones[j] in [
                    "add ", "addu ", "sub ", "subu ", "and ", "or ", "nor ",
                    "slt ", "sltu "
            ]:
                reg = calcular_registro(linea)
                reg = reg.split(" ")
                code += " " + reg[2] + " " + reg[3] + " " + reg[1] + " 00000"
                code += " " + instrucciones_opcode[instrucciones[j]][-1]
            elif instrucciones[j] in ["mult ", "multu ", "div ", "divu "]:
                reg = calcular_registro(linea)
                code += reg + " 00000 00000 "
                code += instrucciones_opcode[instrucciones[j]][-1]
            elif instrucciones[j] in ["mfhi ", "mflo "]:
                reg = calcular_registro(linea)
                reg = reg.split(" ")
                code += " " + "00000" + " " + "00000" + " " + reg[1] + " 00000"
                code += " " + instrucciones_opcode[instrucciones[j]][-1]
            elif instrucciones[j] in ["jr "]:
                code += calcular_registro(linea)
                code += " 00000 11111 00000"
                code += " " + instrucciones_opcode[instrucciones[j]][-1]
            elif instrucciones[j] in ["sll ", "srl ", "sra "]:
                reg = calcular_registro(linea)
                reg = reg.split(" ")
                code += " 00000"
                code += " " + reg[2] + " " + reg[1]
                lineal = linea.split(" ")
                code += " " + str(format(int(lineal[-3]), "05b"))
                code += " " + instrucciones_opcode[instrucciones[j]][-1]

            elif instrucciones[j] in ["jal ", "j "]:
                li = linea.split(" ")
                direccion = calcular_hexa(dir_etiquetas[li[1]] + " ")
                direccion = direccion.replace(" ", "")
                temporal = str(format((int(direccion, 2) // 4), "0b"))
                h = len(temporal)
                ceros = ""
                while h < 26: 
                  ceros += "0"
                  h += 1
                temporal = ceros + temporal
                code += separar_16(temporal)
              
            elif instrucciones[j] in ["beq ", "bne "]:
                reg = calcular_registro(linea)
                reg = reg.split(" ")
                code += " " + reg[2] + " " + reg[1]
              
                li = linea.split(" ")
                direccion = calcular_hexa(dir_etiquetas[li[3]] + " ")
                direccion = direccion.replace(" ", "")
                temp = calcular_hexa(direcciones[i] + " ")
                temp = temp.replace(" ", "")
                temp = int(temp, 2) + 4
                direccion = (int(direccion, 2) - temp) // 4
                direccion = format((direccion), "0b")
                direccion = str(direccion)
                h = len(direccion)
                ceros = ""
                while h < 16: 
                  ceros += "0"
                  h += 1
                direccion = ceros + direccion
                direccion = separar_16(direccion)
                code += direccion

            elif instrucciones[j] in [
                    "addi ", "addiu ", "slti ", "sltiu ", "andi ", "ori "
            ]:
                reg = calcular_registro(linea)
                reg = reg.split(" ")

                code += " " + reg[2] + " " + reg[1] + calcular_hexa(linea)
              
            elif instrucciones[j] in [ "lui "]:
                reg = calcular_registro(linea)
                reg = reg.split(" ")

                code += " 00000 " + reg[1] + calcular_hexa(linea)
            elif instrucciones[j] in [
                    "lw ", "lbu ", "lhu ", "sb ", "sh ", "sw "
            ]:
                reg = calcular_registro(linea)
                reg = reg.split(" ")
                li = linea
                cadena = str(format((int(li.replace(" ", "")[-7])), "016b"))
                cadena = separar_16(cadena)
                code += " " + reg[2] + " " + reg[1] + cadena

    codigo_bin += code + "\n"
print("Codigo_bin:\n" + codigo_bin)
print("Direcciones:\n", direcciones)
print("Etiquetas:\n", dir_etiquetas)