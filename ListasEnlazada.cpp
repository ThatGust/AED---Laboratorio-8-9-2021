 #include <iostream>
 using namespace std;
 
 template<class T>
 class Nodo
 {
    public:
        T  m_Dato;
        Nodo<T> * m_pSig;
    
        
    public:
       Nodo(T d)
       {
          m_Dato = d;
          m_pSig =0;
       }
 };
 
 template<class T>
 class List
 {
     private:
          Nodo<T> * m_pHead;
          Nodo<T> * p_actual;
     public:  
        List()
        {
           m_pHead = 0;
        }    
      
       void push_front(T d)
       {
            if(!m_pHead)  m_pHead =  new Nodo<T>(d);
            else 
            {
                 Nodo<T> * p_tmp =  new Nodo<T>(d);
                 p_tmp->m_pSig = m_pHead;
                 m_pHead = p_tmp; 			
            }        
       }
       void push_back(T d)
       {
           if(!m_pHead)  m_pHead =  new Nodo<T>(d);
           else 
           { 
              Nodo<T> * tmp = m_pHead;
              while(tmp->m_pSig) 
                  tmp=tmp->m_pSig;
              tmp->m_pSig = new Nodo<T>(d);
                 	 
           }  
       }
       bool find(T d)
       {
           Nodo<T> * tmp = m_pHead;
           while(tmp) 
           {
                    if(tmp->m_Dato == d) return true; 
                    tmp = tmp->m_pSig;
                   
           } 
            return false;
           
       } 
       void print()
       {
           Nodo<T> * tmp = m_pHead;
           
           for( ;tmp ; tmp = tmp->m_pSig) 
                    cout<<tmp->m_Dato<<"->";
           cout<<endl;           
       } 
       
       
       
       // print recursivo
       //  add recursivo(siempre al final)
       // find recursivo
      // delete_front
      //  delete_back
      // L1.Union(L2)  L1={1,2,3}  L2={3,1,5}   L1.Union(L2) ={1,2,3,5}  
      // L2.Inter(L2)

        // PREGUNTA 8
        void Begin()
        {
            this->p_actual = this->m_pHead;
        }

        void Last()
        {
            if(!this->m_pHead)
            {
                return;
            }
            for(;this->p_actual->m_pSig;this->p_actual = this->p_actual->m_pSig);
        }

        void Next()
        {
            this->p_actual =  p_actual->m_pSig;
            
        }

        void Previous()
        {
            Nodo <T> * aux = this->p_actual;
            this->p_actual = this->m_pHead;
            for(;this->p_actual->m_pSig != this->aux;this->p_actual = this->p_actual->m_pSig);
            
        }

        
        int Get_Dato()
        {
            return this->p_actual->m_Dato;
        }


      //PRINT RECURSIVO
        void printRecursivo(Nodo<T> *tmp)
       {
           if(tmp!=nullptr){
               cout<<tmp->m_Dato<<endl;
               this->printRecursivo(tmp->m_pSig);
           }        
            
       }
       void mostrarRecursivo(){
           this->printRecursivo(this->m_pHead);
       }

       void printPractica()
        {
            Nodo<T>* temp = m_pHead;
            if (!m_pHead) {
                cout << "La Lista est� vac�a " << endl;
            }
            else {
                while (temp) {
                    temp->printPractica();
                    if (!temp->m_pSig) cout << "NULL";
                    temp = temp->m_pSig;
                }
            }
            cout << endl << endl;
        }

       void agregarRecursivo(Nodo<T> *tmp, T d){
    
            if (tmp->m_pSig == nullptr)
                tmp->m_pSig = new Nodo<T>(d);
            else
                this->agregarRecursivo(tmp->m_pSig, d);
        }
        void mostrarAgregarRecursivo(T d){
            if(m_pHead ==nullptr)
                m_pHead=new Nodo<T>(d);
            else 
                this->agregarRecursivo(this->m_pHead, d);
        }

        bool findRecursivo(Nodo<T> *tmp, T d){
    
            if (tmp == NULL)
                return false;
            if (tmp->m_Dato == d)
                return true;
            return this->findRecursivo(tmp->m_pSig, d);
        }
        
        bool  mostrarfindRecursivo(T d){
           return  this->findRecursivo(this->m_pHead, d);
        }
        void delete_front(){  
            if(!m_pHead)
                return;
            Nodo<T> *tmp= m_pHead->m_pSig;
            delete m_pHead;
            m_pHead = tmp;
        }

        void recursive_print_reverse(Nodo<T> * nodo) 
       {
           if(nodo)
           {
               recursive_print_reverse(nodo->m_pSig);
                cout << nodo->m_Dato << "->";
           }
           else
           {
               cout << '\n';
           }
       }
        void recursive_print() 
        {
            recursive_print_reverse(this->m_pHead);
        }

        int count_even()
        {
            int counter {0};
            Nodo<T> * aux = this->m_pHead;
            for(;aux;aux = aux->m_pSig)
            {
                if(aux->m_Dato % 2 == 0)
                {
                    counter++;
                }
            }
            return counter;
        }

        void sort()
        {
            T temp_data;
            Nodo<T>* aux_node = m_pHead;
            Nodo<T>* temp = aux_node;

            while (aux_node) {
                temp = aux_node;

                while (temp->m_pSig) {
                    temp = temp->m_pSig;

                    if (aux_node->m_Dato < temp->m_Dato) {
                        temp_data = aux_node->m_Dato;
                        aux_node->m_Dato = temp->m_Dato;
                        temp->m_Dato = temp_data;
                    }
                }

                aux_node = aux_node->m_pSig;
            }
        }

        int recursive_max()
        {
            return recursive_max(this->m_pHead,this->m_pHead->m_Dato);
        }

        int recursive_max(Nodo<T> * nodo, T tmp_max)
        {
            if(!nodo)
            {
                return tmp_max;
            }
            if(nodo->m_Dato > tmp_max)
            {
                tmp_max = nodo->m_Dato;
            }
            return recursive_max(nodo->m_pSig,tmp_max);
        }

        int iterative_max()
        {
            Nodo<T> * aux = m_pHead;
            T max_val = aux->m_Dato;
            for(;aux;aux = aux->m_pSig)
            {
                if(aux->m_Dato > max_val)
                {
                    max_val = aux->m_Dato;
                }
            }

            return max_val;
        }

 };
 int main()
 {
   
  /*Nodo<int> A(666);
  cout<<"Dirección del objeto "<<&A<<endl;
  cout<<"Dirección donde vive el dato" << &(A.m_Dato)<<endl;
  cout<<"Dirección donde vide la variable siguiente "<<&(A.m_pSig)<<endl;*/
   List<int> A;
 
   A.push_back(34);
   A.push_back(14);
   A.push_back(434);
   A.push_back(634);
   A.push_back(731);
   A.sort();
   A.recursive_print();
   cout<<endl;
   cout<<A.count_even();
   cout<<endl;
   cout<<A.recursive_max();
   cout<<endl;
   cout<<A.iterative_max();
  /* cout<<A.find(34)<<endl;
   cout<<A.find(14)<<endl;
   cout<<A.find(434)<<endl;
   cout<<A.find(634)<<endl;
   cout<<A.find(734)<<endl;
   cout<<A.find(0)<<endl;
   cout<<A.find(734)<<endl;
   */
   
   return 0;
 }