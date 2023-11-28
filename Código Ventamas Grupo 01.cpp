#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Registro
{
    string usuarios;
    string passwords;
    int tipo;
};
vector<Registro> vecRegistro;

struct Producto
{
    int     codProducto;
    string  nomProducto;
    float   preProducto;
    int     stkProducto = 100;
    int cantProducto;
};
vector<Producto> vecProducto;

//Prototipos
void add(); //Datos preregistro (administradores)
void menuClientes();
void menuVendedores(); // inicio y registro                                 vendedor
void password(char frase[]); //Funcion para cambiar caracteres de la contraseña por asteriscos
void addVector1(); //Inicio Sesion
void addVector2(); //Registrar usuario
void addVector(); //Menu de productos
void listOfItems(); //Listar los productos seleccionados
void generarBoleta();
int getCorrelativo(); //correlativo = valor continuo o números sucesivos, nos generará el número de códigos automaticamente según orden de ingreso de datos
int getCorrelativo2(); // compradores
void sumaTotal(); //Suma total
void buscarProductoPorCodigo(); //buscador del producto                    vendedor
void removerVector(); //Remover producto                                  vendedor
void modifyVector(); //Modificar producto                                  vendedor
int obtenerPosArreglo(int);
void productsgenerales(); //Menu para el vendedor                          vendedor
void Lacteos();
void Carnes();
void ProductosLimpis();
void Snacks();
void TragosC();
void Gaseosas();
void removerVector1();

void add()
{
    //Datos de administradores
    Registro usuario;
    usuario.usuarios = "Michela S";
    usuario.passwords = "tobby";
    usuario.tipo = 1;
    vecRegistro.push_back(usuario);

    vecRegistro.push_back({ "Nayeli C", "nayeli", 1 });

    vecRegistro.push_back({ "Gilmar", "gilmar", 1 });

    vecRegistro.push_back({ "Jonathan C", "jonathan", 1 });

}//Datos preregistro
// Declaración de funciones
void add();
void menuClientes();
void addVector();
void menuVendedores();

int main() {
    add();
    int op;
    cout << "\t\t\t\t\t _______________________________" << endl;
    cout << "\t\t\t\t\t|                               |" << endl;
    cout << "\t\t\t\t\t|\t   BIENVENIDO           |" << endl;
    cout << "\t\t\t\t\t|                               |" << endl;
    cout << "\t\t\t\t\t|   Cliente                [1]  |" << endl;
    cout << "\t\t\t\t\t|   Vendedor               [2]  |" << endl;
    cout << "\t\t\t\t\t|   Salir                  [3]  |" << endl;
    cout << "\t\t\t\t\t|_______________________________|" << endl;
    cout << "\n\t\t\t\t\t   Ingrese una opcion:      ";
    cin >> op;

    switch (op) {
    case 1:
        system("cls");
        menuClientes();
        addVector();
        system("pause");
        break;
    case 2:
        system("cls");
        menuVendedores();
        break;
    case 3:
        system("cls");
        exit(0);
        break;
    default:
        break;
    }

    return 0;
}


void menuClientes()
{
    char opcion;
    bool bandera = true;
    do
    {
        cout << "\t\t\t\t\t _______________________________" << endl;
        cout << "\t\t\t\t\t|                               |" << endl;
        cout << "\t\t\t\t\t|     VENTAMAS - CLIENTES       |" << endl;
        cout << "\t\t\t\t\t|                               |" << endl;
        cout << "\t\t\t\t\t|  Inicio de Sesion        [1]  |" << endl;
        cout << "\t\t\t\t\t|  Registrarse             [2]  |" << endl;
        cout << "\t\t\t\t\t|  Ingresar como invitado  [3]  |" << endl;
        cout << "\t\t\t\t\t|  Salir                   [4]  |" << endl;
        cout << "\t\t\t\t\t|_______________________________|" << endl;
        cout << "\n\t\t\t\t\t   Ingrese una opcion:      ";
        cin >> opcion;
        switch (opcion)
        {
        case '1':
            system("cls");
            addVector1();
            system("pause");
            system("cls");
            addVector();
            break;
        case '2':
            system("cls");
            addVector2();
            break;
        case '3':
            system("cls");
            addVector();
            break;
        case '4':
            system("cls");
            main();
            break;

        default:
            system("cls");
            cout << "¡Ingrese una opción correcta!";
            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 4);
}
void menuVendedores()
{
    int opcion;
    do
    {
        cout << "\t\t\t\t\t _______________________________" << endl;
        cout << "\t\t\t\t\t|                               |" << endl;
        cout << "\t\t\t\t\t|     VENTAMAS - VENDEDORES     |" << endl;
        cout << "\t\t\t\t\t|                               |" << endl;
        cout << "\t\t\t\t\t|  Inicio de Sesion        [1]  |" << endl;
        cout << "\t\t\t\t\t|  Registrarse             [2]  |" << endl;
        cout << "\t\t\t\t\t|  Salir                   [3]  |" << endl;
        cout << "\t\t\t\t\t|_______________________________|" << endl;
        cout << "\n\t\t\t\t\t   Ingrese una opcion:      ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            addVector1();
            system("pause");
            system("cls");
            productsgenerales();
            break;
        case 2:
            system("cls");
            addVector2();
            break;
        case 3:
            system("cls");
            main();
            break;
        default:
            system("cls");
            cout << "¡Ingrese una opción correcta!";
            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 4);
}

void password(char frase[]) //funcion para pedir contraseña y mostrar sus caracteres como asteriscos
{
    int i = 0;
    cout.flush();

    do
    {
        frase[i] = (unsigned char)_getch();

        if (frase[i] != 8)
        {
            cout << '*';
            i++;
        }
        else if (i > 0)
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;
        }
    } while (frase[i - 1] != 13);
    frase[i - 1] = '\0';
    cout << endl;
}
void addVector1()
{
    string usuario;
    string rpta;
    char miau[20];
    bool bandera = true;
    do
    {
        cin.ignore();

        cout << "\n\t\t\t\t\t**********INICIO DE SESION**********";
        cout << "\n\t\t\t\t\tUsuario:  \t";
        getline(cin, usuario);
        cout << "\t\t\t\t\tContraseña: \t";
        password(miau); //llamado a a funcion para mostrar los caracteres de la contraseña como asteriscos
        for (int i = 0; i < vecRegistro.size(); i++)
        {
            if (usuario == vecRegistro[i].usuarios)
            {
                if (miau == vecRegistro[i].passwords)
                {
                    bandera = false;
                    break;
                }
            }
        }
        if (bandera == false)
        {
            cout << "\t\t\t\t\tNombre y contraseña encontrada" << endl;
            break;
        }
        else
        {
            cout << "\t\t\t\t\tRegistro no encontrado" << endl;
            cout << "\t\t\t\t\tDesea repetir? [S-N]: " << endl;
            cin >> rpta;
        }
        system("cls");
        if (rpta == "n" || rpta == "N")
        {
            menuClientes();
        }
    } while (rpta == "s" || rpta == "S");
}
void addVector2()
{
    Registro registro;
    cin.ignore();
    cout << "\t\t\t\t\t**********R E G I S T R A R S E**********" << endl;
    cout << "\t\t\t\t\tUsuario: ";
    getline(cin, registro.usuarios);
    cout << "\t\t\t\t\tContraseña: ";
    cin >> registro.passwords;
    system("cls");
    cout << "\t\t\t\t\tREGISTRADO CON EXITO!!!!!!!!!\n";
    system("pause");
    vecRegistro.push_back(registro);
    system("cls");
}

// adentro de la aplicacion

void addVector()
{
    string rpta;
    int _rpta;

    do
    {
        Producto producto;//Declarando el tipo de datos estructura
        //se agregan elementos a los atributos de la estructura
        //cout << "Código:" << getCorrelativo(); // getCorrelativo() genera el código automaticamente, producto.codProducto se usa para almacenar los datos
        //producto.codProducto = getCorrelativo();
        //Para limpiar el buffer, limpiar los datos
        cout << "\t\t\t\t\t ________________________________________" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|                  MENU                  |" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|   Lacteos                         [1]  |" << endl;
        cout << "\t\t\t\t\t|   Carnes                          [2]  |" << endl;
        cout << "\t\t\t\t\t|   Productos de limpieza           [3]  |" << endl;
        cout << "\t\t\t\t\t|   Snacks                          [4]  |" << endl;
        cout << "\t\t\t\t\t|   Tragos cortos                   [5]  |" << endl;
        cout << "\t\t\t\t\t|   Gaseosas                        [6]  |" << endl;
        cout << "\t\t\t\t\t|   Generar boleta                  [7]  |" << endl;
        cout << "\t\t\t\t\t|   Salir                           [8]  |" << endl;
        cout << "\t\t\t\t\t|________________________________________|" << endl;
        cout << "\n\t\t\t\t\t    Elija una opcion:                ";
        cin >> _rpta;
        switch (_rpta)
        {
        case 1:
            system("cls");
            Lacteos();
            break;

        case 2:
            system("cls");
            Carnes();
            break;
        case 3:
            system("cls");
            ProductosLimpis();
            break;

        case 4:
            system("cls");
            Snacks();
            break;

        case 5:
            system("cls");
            TragosC();
            break;
        case 6:
            system("cls");
            Gaseosas();
            break;
        case 7:
            system("cls");
            generarBoleta();
            exit(0);
            break;
        case 8:
            system("cls");
            break;

        default:
            system("cls");
            cout << "\n\t\t\t\t\t ________________________________________" << endl;
            cout << "\t\t\t\t\t|                                        |" << endl;
            cout << "\t\t\t\t\t|            OPCION INVALIDA             |" << endl;
            cout << "\t\t\t\t\t|________________________________________|" << endl;

            system("pause");
            system("cls");
            break;
        }
        cout << "\n\t\t\t\t\tDeseas continuar registrando productos...(S/s):";
        cin >> rpta;
        system("cls");
    } while (rpta == "S" || rpta == "s");
}
void Lacteos()
{
    int n1, cant;
    Producto producto;
    for (;;)
    {
        system("cls");
        cout << "\t\t\t\t\t ________________________________________" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|                LACTEOS                 |" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|   Leche de vaca  (S/9.50)         [1]  |" << endl;
        cout << "\t\t\t\t\t|   Leche de oveja (S/10.50)        [2]  |" << endl;
        cout << "\t\t\t\t\t|   Leche en polvo (S/5.00)         [3]  |" << endl;
        cout << "\t\t\t\t\t|   Crema de leche (S/9.00)         [4]  |" << endl;
        cout << "\t\t\t\t\t|   Crema de nata  (S/7.00)         [5]  |" << endl;
        cout << "\t\t\t\t\t|   Queso          (S/8.90)         [6]  |" << endl;
        cout << "\t\t\t\t\t|   Yogurt         (S/6.50)         [7]  |" << endl;
        cout << "\t\t\t\t\t|   Volver         (S/6.50)         [8]  |" << endl;
        cout << "\t\t\t\t\t|________________________________________|" << endl;
        cout << "\n\t\t\t\t\t    Elija una opcion:                ";
        cin >> n1;
        if (n1 == 1)
        {
            cout << "\t\t\t\t\tCodigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Leche de vaca";
            producto.preProducto = 9.5;
            cout << "\t\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 2)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Leche de oveja";
            producto.preProducto = 10.5;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);


        }
        else if (n1 == 3)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Leche en polvo";
            producto.preProducto = 5;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 4)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Crema de leche";
            producto.preProducto = 9;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 5)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Crema de nata";
            producto.preProducto = 7;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 6)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Queso";
            producto.preProducto = 8.9;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 7)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Yogurt";
            producto.preProducto = 6.5;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 8)
        {
            break;
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\t ________________________________________" << endl;
            cout << "\t\t\t\t\t|                                        |" << endl;
            cout << "\t\t\t\t\t|            OPCION INVALIDA             |" << endl;
            cout << "\t\t\t\t\t|________________________________________|" << endl;

            system("pause");
            system("cls");
        }
    }
}
void Carnes()
{
    int n1, cant;
    Producto producto;
    for (;;)
    {
        system("cls");
        cout << "\t\t\t\t\t ________________________________________" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|                 CARNES                 |" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|   Carne blanca    (S/10.50)       [1]  |" << endl;
        cout << "\t\t\t\t\t|   Carne Roja      (S/12.50)       [2]  |" << endl;
        cout << "\t\t\t\t\t|   Carne vacuno    (S/15.50)       [3]  |" << endl;
        cout << "\t\t\t\t\t|   Carne porcina   (S/12.00)       [4]  |" << endl;
        cout << "\t\t\t\t\t|   Carne ovina     (S/18.50)       [5]  |" << endl;
        cout << "\t\t\t\t\t|   Carne de ave    (S/7.00)        [6]  |" << endl;
        cout << "\t\t\t\t\t|   Carne de reptil (S/16.00)       [7]  |" << endl;
        cout << "\t\t\t\t\t|   Volver                          [8]  |" << endl;
        cout << "\t\t\t\t\t|________________________________________|" << endl;
        cout << "\n\t\t\t\t\t    Elija una opcion:                ";
        cin >> n1;
        if (n1 == 1)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Carne Blanca";
            producto.preProducto = 10.5;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);
        }
        else if (n1 == 2)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Carne Roja";
            producto.preProducto = 12.5;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 3)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Carne vacuno";
            producto.preProducto = 15.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 4)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Carne porcina";
            producto.preProducto = 12.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 5)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Carne ovina";
            producto.preProducto = 18.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 6)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Carne de ave";
            producto.preProducto = 7.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 7)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Carne de reptil";
            producto.preProducto = 16.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 8)
        {
            break;
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\t ________________________________________" << endl;
            cout << "\t\t\t\t\t|                                        |" << endl;
            cout << "\t\t\t\t\t|            OPCION INVALIDA             |" << endl;
            cout << "\t\t\t\t\t|________________________________________|" << endl;

            system("pause");
            system("cls");

        }
    }
}
void ProductosLimpis()
{
    int n1, cant;
    Producto producto;
    for (;;)
    {
        system("cls");
        cout << "\t\t\t\t\t ________________________________________" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|        Productos de limpieza           |" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t| L.accion desinfectante  (S/12.50) [1]  |" << endl;
        cout << "\t\t\t\t\t| Toallas humedas         (S/9.50)  [2]  |" << endl;
        cout << "\t\t\t\t\t| B.de limpieza           (S/7.50)  [3]  |" << endl;
        cout << "\t\t\t\t\t| Limpiavidrios           (S/5.50)  [4]  |" << endl;
        cout << "\t\t\t\t\t| Antisarro               (S/6.50)  [5]  |" << endl;
        cout << "\t\t\t\t\t| Detergente              (S/5.50)  [6]  |" << endl;
        cout << "\t\t\t\t\t| Volver                            [7]  |" << endl;
        cout << "\t\t\t\t\t|________________________________________|" << endl;
        cout << "\n\t\t\t\t\t    Elija una opcion:                ";
        cin >> n1;
        if (n1 == 1)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Limpiador con acción desinfectante";
            producto.preProducto = 12.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 2)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Toallas humedas";
            producto.preProducto = 9.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 3)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Bicarbonato de limpieza";
            producto.preProducto = 7.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 4)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Limpiavidrios";
            producto.preProducto = 5.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 5)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Antisarro";
            producto.preProducto = 6.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 6)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Detergente";
            producto.preProducto = 5.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 7)
        {
            break;
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\t ________________________________________" << endl;
            cout << "\t\t\t\t\t|                                        |" << endl;
            cout << "\t\t\t\t\t|            OPCION INVALIDA             |" << endl;
            cout << "\t\t\t\t\t|________________________________________|" << endl;

            system("pause");
            system("cls");

        }
    }
}
void Snacks()
{
    int n1, cant;
    Producto producto;
    for (;;)
    {
        system("cls");
        cout << "\t\t\t\t\t ________________________________________" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|                 SNACKS                 |" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|   Doritos        (S/7.50)         [1]  |" << endl;
        cout << "\t\t\t\t\t|   Cheetos        (S/8.50)         [2]  |" << endl;
        cout << "\t\t\t\t\t|   Papitas        (S/7.00)         [3]  |" << endl;
        cout << "\t\t\t\t\t|   Piqueos        (S/8.50)         [4]  |" << endl;
        cout << "\t\t\t\t\t|   Munchies       (S/8.00)         [5]  |" << endl;
        cout << "\t\t\t\t\t|   Volver                          [6]  |" << endl;
        cout << "\t\t\t\t\t|________________________________________|" << endl;
        cout << "\n\t\t\t\t\t    Elija una opcion:                ";
        cin >> n1;
        if (n1 == 1)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Doritos";
            producto.preProducto = 7.50;
            cout << "\t\t\t\t\tIngrese la cantidad: ";
            cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 2)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Cheetos";
            producto.preProducto = 8.50;
            cout << "\t\t\t\t\tIngrese la cantidad: ";
            cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 3)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Papitas";
            producto.preProducto = 7.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 4)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Piqueos";
            producto.preProducto = 8.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 5)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Munchies";
            producto.preProducto = 8.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 6)
        {
            break;
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\t ________________________________________" << endl;
            cout << "\t\t\t\t\t|                                        |" << endl;
            cout << "\t\t\t\t\t|            OPCION INVALIDA             |" << endl;
            cout << "\t\t\t\t\t|________________________________________|" << endl;

            system("pause");
            system("cls");

        }
    }
}
void TragosC()
{
    int n1, cant;
    Producto producto;
    for (;;)
    {
        system("cls");
        cout << "\t\t\t\t\t ________________________________________" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|                 TRAGOS                 |" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|   Vino           (S/25.99)        [1]  |" << endl;
        cout << "\t\t\t\t\t|   Vodka          (S/69.90)        [2]  |" << endl;
        cout << "\t\t\t\t\t|   Champagne      (S/61.90)        [3]  |" << endl;
        cout << "\t\t\t\t\t|   Pisco          (S/39.90)        [4]  |" << endl;
        cout << "\t\t\t\t\t|   Wisky          (S/85.90)        [5]  |" << endl;
        cout << "\t\t\t\t\t|   Cerveza        (S/11.90)        [6]  |" << endl;
        cout << "\t\t\t\t\t|   Volver                          [7]  |" << endl;
        cout << "\t\t\t\t\t|________________________________________|" << endl;
        cout << "\n\t\t\t\t\t    Elija una opcion:                ";
        cin >> n1;
        if (n1 == 1)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Vino";
            producto.preProducto = 25.99;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 2)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Vodka";
            producto.preProducto = 69.90;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 3)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Champagne";
            producto.preProducto = 61.90;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 4)
        {

            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Pisco";
            producto.preProducto = 39.90;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 5)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Whisky";
            producto.preProducto = 85.90;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 6)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Cerveza";
            producto.preProducto = 11.90;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 7)
        {
            break;
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\t ________________________________________" << endl;
            cout << "\t\t\t\t\t|                                        |" << endl;
            cout << "\t\t\t\t\t|            OPCION INVALIDA             |" << endl;
            cout << "\t\t\t\t\t|________________________________________|" << endl;

            system("pause");
            system("cls");

        }
    }
}
void Gaseosas()
{
    int n1, cant;
    Producto producto;
    for (;;)
    {
        system("cls");
        cout << "\t\t\t\t\t ________________________________________" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|               GASEOSAS                 |" << endl;
        cout << "\t\t\t\t\t|                                        |" << endl;
        cout << "\t\t\t\t\t|   Inca Kola      (S/12.00)        [1]  |" << endl;
        cout << "\t\t\t\t\t|   Coca Cola      (S/12.00)        [2]  |" << endl;
        cout << "\t\t\t\t\t|   Pepsi          (S/9.00)         [3]  |" << endl;
        cout << "\t\t\t\t\t|   Fanta          (S/10.50)        [4]  |" << endl;
        cout << "\t\t\t\t\t|   Sprite         (S/9.50)         [5]  |" << endl;
        cout << "\t\t\t\t\t|   Volver                          [6]  |" << endl;
        cout << "\t\t\t\t\t|________________________________________|" << endl;
        cout << "\n\t\t\t\t\t    Elija una opcion:                ";
        cin >> n1;
        if (n1 == 1)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Inca Kola";
            producto.preProducto = 12.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 2)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Coca Cola";
            producto.preProducto = 12.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 3)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Pepsi";
            producto.preProducto = 9.00;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 4)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Fanta";
            producto.preProducto = 10.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 5)
        {
            cout << "\t\t\t\t\tCódigo:" << getCorrelativo() << endl;
            producto.codProducto = getCorrelativo();
            producto.nomProducto = "Sprite";
            producto.preProducto = 9.50;
            cout << "\t\t\t\t\tIngrese la cantidad: "; cin >> cant;
            producto.cantProducto = cant;
            vecProducto.push_back(producto);

        }
        else if (n1 == 6)
        {
            break;
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\t\t ________________________________________" << endl;
            cout << "\t\t\t\t\t|                                        |" << endl;
            cout << "\t\t\t\t\t|            OPCION INVALIDA             |" << endl;
            cout << "\t\t\t\t\t|________________________________________|" << endl;

            system("pause");
            system("cls");
        }
    }
}
void listOfItems()
{
    cout << "\nREPORTE GENERAL DE PRODUCTOS REGISTRADOS";
    for (int i = 0; i < vecProducto.size(); i++) // i representa la posición, en este caso comienza desde 0 y va aumentando de 1 en 1 (i++)
    {
        cout << "\n-------------------------------------";
        cout << "\nCódigo:" << vecProducto[i].codProducto; //vecProducto representa todas las variables almacenada
        cout << "\nNombre:" << vecProducto[i].nomProducto; //vecProducto[i] las variables almacenadas en la posición requerida
        cout << "\nPrecio:" << vecProducto[i].preProducto; //vecProducto[i].codProducto la variable almacenada del código del producto
        cout << "\nCantidad a comprar:" << vecProducto[i].cantProducto;
        cout << "\nCoste por producto: " << vecProducto[i].cantProducto * vecProducto[i].preProducto;
        cout << "\nStock:" << vecProducto[i].stkProducto;
        cout << "\n-------------------------------------\n";
    }
    sumaTotal();
}

int getCorrelativo()
{
    if (vecProducto.size() == 0) // No tengo datos registrados en el arreglo
    {
        return 1;//retornar el código 1  
    }
    else
    {
        return vecProducto[vecProducto.size() - 1].codProducto + 1; // vecProducto.size() -1 representa la posición porque inicia desde 0, .codProducto + 1 solo entrega el específico y más 1 porque cuando es posición 3 esta guardado los datos 4
    }
}

int getCorrelativo2()
{
    if (vecProducto.size() == 0) // No tengo datos registrados en el arreglo
    {
        return 1;//retornar el código 1  
    }
    else
    {
        return vecProducto[vecProducto.size() - 1].codProducto + 1; // vecProducto.size() -1 representa la posición porque inicia desde 0, .codProducto + 1 solo entrega el específico y más 1 porque cuando es posición 3 esta guardado los datos 4
    }
}

void sumaTotal()
{
    float suma = 0;

    for (int i = 0; i < vecProducto.size(); i++)
    {
        suma += (vecProducto[i].preProducto * vecProducto[i].cantProducto); // vecProducto[i].preProducto llama a todos los precios de los productos y suma+= los suma
    }
    cout << "Total:       \t\t\t" << suma << endl;
}

void buscarProductoPorCodigo()
{
    int codigo,
        pos;
    bool flag = false;

    cout << "\nIngrese código a buscar:";
    cin >> codigo;
    for (int i = 0; i < vecProducto.size(); i++)
    {
        if (codigo == vecProducto[i].codProducto)
        {
            pos = i; //porque i comienza en 0 y va marcando la posición
            flag = true;
        }
    }
    if (flag == true) //lo encontró
    {
        system("cls");
        cout << "\nRegistro encontrado en la posición (" << pos << ")";
        system("pause");
        system("cls");
        cout << "\nCódigo" << vecProducto[pos].codProducto;
        cout << "\nNombre:" << vecProducto[pos].nomProducto;
        cout << "\nPrecio:" << vecProducto[pos].preProducto;
        cout << "\nStock:" << vecProducto[pos].stkProducto;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "\nCódigo ingresado no existe :(";
        system("pause");
        system("cls");
    }
}

void removerVector()
{
    int codigo;
    bool flag = false;

    cout << "Ingrese código del producto a eliminar: ";
    cin >> codigo;
    for (int i = 0; i < vecProducto.size(); i++)
    {
        if (codigo == vecProducto[i].codProducto)
        {
            vecProducto.erase(vecProducto.begin() + i);
            cout << "\nRegistro eliminado satisfactoriamente :)";
            flag = true;
            break;
        }
    }
    if (flag = false)
    {
        cout << "\nERROR: código del producto no encontrado :(";
    }
}
void removerVector1()
{
    for (int i = 0; i < vecProducto.size(); i++)
    {
        vecProducto.erase(vecProducto.begin() + i);
    }
    cout << "\n\t\t\t\t\tRegistro eliminado satisfactoriamente :)" << endl;
}

void modifyVector()
{
    int codigo,
        posicion,
        opcion;
    string _nombre;
    float _precio;
    int _stock;

    cout << "Ingrese un código a modificar: ";
    cin >> codigo;
    posicion = obtenerPosArreglo(codigo);
    if (posicion == -1)
    {
        cout << "\nERROR: código ingresado no existe!";
    }
    else
    {
        cout << "\nRegistro encontrado";
        cout << "\n-----------------------";
        cout << "Código" << vecProducto[posicion].codProducto << endl;
        cout << "Nombre" << vecProducto[posicion].nomProducto << endl;
        cout << "Precio" << vecProducto[posicion].preProducto << endl;
        cout << "Stock" << vecProducto[posicion].stkProducto << endl;
        cout << "\nMINI MENÚ";
        cout << "\n\t\tNombre [1]";
        cout << "\n\t\tPrecio [2]";
        cout << "\n\t\tStock  [3]";
        cout << "\n\t\tSalir  [4]";
        cout << "\nSelecciona una opción [1-4]: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout << "Cambiar nombre: ";
            getline(cin, _nombre);
            vecProducto[posicion].nomProducto = _nombre;
            break;
        case 2:
            cout << "Cambiar precio: ";
            cin >> _precio;
            vecProducto[posicion].preProducto = _precio;
            break;
        case 3:
            cout << "Cambiar stock: ";
            cin >> _stock;
            vecProducto[posicion].preProducto = _stock;
            break;
        case 4:
            break;
        default: cout << "\nIngrese una opción correcta [1-4]...";
            break;
        }
    }

}

int obtenerPosArreglo(int cod)
{
    for (int i = 0; i < vecProducto.size(); i++)
    {
        if (cod == vecProducto[i].codProducto)
        {
            return i;
        }
    }
    return -1; //si no encuenta devuelve -1 porque esa posición no existe
}

void productsgenerales()
{
    int opcion;
    do
    {
        cout << "\t\t\t\t\t ________________________________" << endl;
        cout << "\t\t\t\t\t|                                |" << endl;
        cout << "\t\t\t\t\t|        MENU DE OPCIONES        |" << endl;
        cout << "\t\t\t\t\t|                                |" << endl;
        cout << "\t\t\t\t\t|  Agregar productos        [1]  |" << endl;
        cout << "\t\t\t\t\t|  Buscar productos         [2]  |" << endl;
        cout << "\t\t\t\t\t|  Eliminar productos       [3]  |" << endl;
        cout << "\t\t\t\t\t|  Modificar productos      [4]  |" << endl;
        cout << "\t\t\t\t\t|  Listar productos         [5]  |" << endl;
        cout << "\t\t\t\t\t|  Generar                  [6]  |" << endl;
        cout << "\t\t\t\t\t|  Salir                    [7]  |" << endl;
        cout << "\t\t\t\t\t|________________________________|" << endl;
        cout << "\n\t\t\t\t\t   Ingrese una opcion:      ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            addVector();
            break;
        case 2:
            system("cls");
            buscarProductoPorCodigo();
            break;
        case 3:
            system("cls");
            removerVector();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            modifyVector();
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            listOfItems();
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            generarBoleta();
            system("pause");
            system("cls");
            exit(0);
            break;
        case 7:
            system("cls"); cout << "\nGracias por su compra" << endl;
            system("pause");
            system("cls");
            break;

        default:
            system("cls");
            cout << "\nIngrese opcion correcta [1-6]";
            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 7);
}

void generarBoleta()
{
    string nombre, dia, mes, year, rpta;
    cout << "Ingrese nombre del cliente: "; cin >> nombre; //12 caracteres para centrar
    cout << "Ingrese la fecha: ";
    cin >> dia;
    system("cls");
    cout << "Ingrese nombre del cliente: " << nombre << endl;
    cout << "Ingrese la fecha: " << dia << "/";
    cin >> mes;
    system("cls");
    cout << "Ingrese nombre del cliente: " << nombre << endl;
    cout << "Ingrese la fecha: " << dia << "/" << mes << "/";
    cin >> year;

    system("cls");
    cout << "\t\t\t\t\t ________________________________________" << endl;
    cout << "\t\t\t\t\t                                        " << endl;
    cout << "\t\t\t\t\t                VENTAMAS                " << endl;
    cout << "\t\t\t\t\t             VENTAMAS S.A.C.            " << endl;
    cout << "\t\t\t\t\t         LIMA - LIMA - LA MOLINA        " << endl;
    cout << "\t\t\t\t\t         Campus 2 USIL La Fontana       " << endl;
    cout << "\t\t\t\t\t       BOLETA DE VENTA ELECTRONICA      " << endl;
    cout << "\t\t\t\t\t                                        " << endl;
    cout << "\t\t\t\t\t  FECHA DE EMISION:    " << dia << "/" << mes << "/" << year << "       " << endl;
    cout << "\t\t\t\t\t  NOMBRE DE COMPRADOR: " << nombre << "         " << endl;
    cout << "\t\t\t\t\t________________________________________" << endl;
    cout << "\t\t\t\t\t  Descripcion:                          " << endl;
    cout << "\t\t\t\t\t    Cantidad x P. Unitario      Total   " << endl;
    cout << "\t\t\t\t\t________________________________________" << endl;
    cout << "\t\t\t\t\t                                        " << endl;
    for (int i = 0; i < vecProducto.size(); i++) // i representa la posición, en este caso comienza desde 0 y va aumentando de 1 en 1 (i++)
    {
        cout << "\t\t\t\t\t" << vecProducto[i].nomProducto << endl; //vecProducto[i] las variables almacenadas en la posición requerida
        cout << "\t\t\t\t\t\t" << vecProducto[i].preProducto << " x " << vecProducto[i].cantProducto;
        cout << "\t\t   " << vecProducto[i].cantProducto * vecProducto[i].preProducto << endl;
        if (i + 1 < vecProducto.size())
        {
            cout << "\t\t\t\t\t--------------------------------------\n";
        }
        else
        {
            cout << " " << endl;
        }
    }

    cout << "\t\t\t\t\t________________________________________" << endl << endl;
    cout << "\t\t\t\t\t";  sumaTotal();
    cout << "\t\t\t\t\t________________________________________" << endl;
}


