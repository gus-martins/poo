#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <memory>
#include <stdexcept>
#include <algorithm>

using namespace std;

class MessageException : public exception {
   string message;
public:
    MessageException(const string& message) : 
        message(message) {
    }
    const char* what() const noexcept override {
        return message.c_str(); 
    }
};

class IMedico;

class IPaciente{
public:
    virtual void addMedico(IMedico* medico) = 0;
    virtual string getDiagnostico() = 0;
    virtual string getId() = 0;
    virtual vector<IMedico*> getMedicos() = 0;
    virtual void removerMedico(string medicoId) = 0;
    virtual string toString() = 0;
    virtual ~IPaciente(){};
};

class IMedico{
public:
    virtual void addPaciente(IPaciente* paciente) = 0;
    virtual string getClasse() = 0;
    virtual string getId() = 0;
    virtual vector<IPaciente*> getPacientes() = 0;
    virtual void removerPaciente(string pacienteId) = 0;
    virtual string toString() = 0;
    virtual ~IMedico(){};
};

class Paciente : public IPaciente{
protected:
    string id;
    string diagnostico;
    map<string, IMedico*> medicos;

public:
    Paciente(string id, string diagnostico) : id{id}, diagnostico{diagnostico} {}
    
    string toString() override{
        stringstream ss;
        int size = 1;

        ss << "Pac: " << this->getId() << ":" << this->getDiagnostico() << "  Meds[";
        
        for(auto medico : this->getMedicos()){
            if(size < (int) this->getMedicos().size()){
                ss << medico->getId() << ",";
            }else{
                ss << medico->getId();
            }

            size++;    
        }

        ss << "]";
        
        return ss.str();
    }

    void addMedico(IMedico* medico) override{
        this->medicos[medico->getId()] = medico;
    }

    string getDiagnostico() override{
        return this->diagnostico;
    }

    string getId() override{
        return this->id;
    }

   vector<IMedico*> getMedicos() override{
        vector<IMedico*> temp;

        for(auto medico : this->medicos){
            temp.push_back(medico.second);
        }

        return temp;
    }

    void removerMedico(string medicoId) override{
        this->medicos.erase(medicoId);
    }
};

class Medico : public IMedico{
protected:
    string id;
    string classe;
    map<string, IPaciente*> pacientes;

public:
    Medico(string id, string classe) : id{id}, classe{classe} {}

    string toString() override{
        stringstream ss;
        int size = 1;

        ss << "Medico: " << this->getId() << ":" << this->getClasse()<< "  Pacientes [";

        for(auto paciente : this->getPacientes()){
            if(size < (int) this->getPacientes().size()){
                ss << paciente->getId() << ",";
            }else{
                ss << paciente->getId();
            }

            size++;    
        }

        ss << "]";

        return ss.str();
    }

    void addPaciente(IPaciente* paciente) override{
        this->pacientes[paciente->getId()] = paciente;
    };

    string getClasse() override{
        return this->classe;
    }

    string getId() override{
        return this->id;
    }

    vector<IPaciente*> getPacientes() override{
      vector<IPaciente*> temp;

        for(auto paciente : this->pacientes){
            temp.push_back(paciente.second);
        }

        return temp;
    }

    void removerPaciente(string pacienteId) override{
        this->pacientes.erase(pacienteId);
    }
};

class Hospital{
private:
    map<string, shared_ptr<IPaciente>> pacientes;
    map<string, shared_ptr<IMedico>> medicos;

public:
    Hospital(){}

    void addMedico(shared_ptr<IMedico> medico){
       if(this->medicos.find(medico->getId()) == this->medicos.end()){
            medicos[medico->getId()] = medico;
       }else{
           throw MessageException("fail: medico ja cadastrado");
       }
    }

    void addPaciente(shared_ptr<IPaciente> paciente){
        if(this->pacientes.find(paciente->getId()) == this->pacientes.end()){
            pacientes[paciente->getId()] = paciente;
        }else{
            throw MessageException("fail: paciente ja cadastrado");
        }
    }

    void removerMedico(string id) {
        if(this->medicos.find(id) != this->medicos.end()){
            for(auto paciente : this->medicos[id].get()->getPacientes()){
                paciente->removerMedico(id);
            }
            this->medicos.erase(id);
        }else{
            throw MessageException("medico inexistente");
        }
    }

    void removerPaciente(string id) {
        if(this->pacientes.find(id) != this->pacientes.end()){
            for(auto medico : this->pacientes[id].get()->getMedicos()){
                medico->removerPaciente(id);
            }
            this->pacientes.erase(id);
        }else{
            throw MessageException("paciente inexistente");
        }
    }

    string showAll(){
        stringstream ss;

        for(auto paciente : this->pacientes){
            ss << paciente.second->toString() << "\n";
        }

        for(auto medico : this->medicos){
           ss << medico.second->toString() << "\n";
        }

        return ss.str();
    }

    void vincular(string medicoId, string pacienteId){

        if((this->pacientes.find(pacienteId) == this->pacientes.end()) || this->medicos.find(medicoId) == this->medicos.end()){
            throw MessageException("nome do paciente ou medico incorreto");
        
        }else{
            auto pacientesMed = this->pacientes[pacienteId].get()->getMedicos();
            if(find(pacientesMed.begin(), pacientesMed.end(), this->medicos[medicoId].get()) != pacientesMed.end()){
                throw MessageException("medico e paciente ja vinculados");
            }else{
                for(auto medico : this->pacientes[pacienteId].get()->getMedicos()){
                    if(medico->getClasse() == this->medicos[medicoId]->getClasse()){
                        throw MessageException("ja existe um medico com esta especialidade " + this->medicos[medicoId]->getClasse());
                    }
                }

                this->medicos[medicoId]->addPaciente(this->pacientes[pacienteId].get());
                this->pacientes[pacienteId]->addMedico(this->medicos[medicoId].get());
            }
        }
    }

    void desvincular(string medicoId, string pacienteId){
        this->medicos[medicoId]->removerPaciente(this->pacientes[pacienteId]->getId());
        this->pacientes[pacienteId]->removerMedico(this->medicos[medicoId]->getId());
    }
    
};


int main() {
    Hospital hospital;

    while (true){
        string linha{""};
        string comando{""};

        

        getline(cin, linha);

        stringstream ss(linha);

        ss >> comando;

        try{
            if(comando == "addPacient"){
            string temp;

            while(ss >> temp){
               int pos = temp.find("-");

               string paciente = temp.substr(0, pos);
               string diagnostico = temp.substr(pos + 1);

               hospital.addPaciente(make_shared<Paciente>(paciente, diagnostico));
            }

            }else if(comando == "addDoc"){
                string temp;

                while(ss >> temp){
                int pos = temp.find("-");

                string id = temp.substr(0, pos);
                string classe = temp.substr(pos + 1);

                hospital.addMedico(std::make_shared<Medico>(id, classe));
                }

            }else if(comando == "removePac"){
                string pacId;

                ss >> pacId;

                hospital.removerPaciente(pacId);
            
            }else if(comando == "removeMed"){
                std::string medId;

                ss >> medId;

                hospital.removerMedico(medId);
            
            }else if(comando == "show"){
                cout << hospital.showAll();
            
            }else if(comando == "tie"){
                string medId;
                string pacId;

                ss >> medId;

                while(ss >> pacId){
                    hospital.vincular(medId, pacId);
                }
            
            }else if(comando == "untie"){
                string medId;
                string pacId;

                ss >> medId >> pacId;

            }else if(comando == "end"){
                break;
            
            }else{
                throw MessageException("fail: comando invalido");
            }
 
        }
        catch(MessageException& e){
            cout << e.what() << endl;
        }
        

    }
    
}