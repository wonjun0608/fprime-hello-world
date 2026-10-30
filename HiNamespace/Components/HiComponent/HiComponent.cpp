// ======================================================================
// \title  HiComponent.cpp
// \author kim-wonjun
// \brief  cpp file for HiComponent component implementation class
// ======================================================================

#include "HiNamespace/Components/HiComponent/HiComponent.hpp"

namespace HiNamespace {

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

HiComponent ::HiComponent(const char* const compName) : HiComponentComponentBase(compName) {}

HiComponent ::~HiComponent() {}

// ----------------------------------------------------------------------
// Handler implementations for commands
// ----------------------------------------------------------------------

void HiComponent::SAY_HI_cmdHandler(
    FwOpcodeType opCode,
    U32 cmdSeq,
    const Fw::CmdStringArg& greeting
) {
    Fw::LogStringArg eventGreeting(greeting.toChar());

    this->log_ACTIVITY_HI_SayHiEvent(eventGreeting);

    this->tlmWrite_GreetingCount(++this->m_greetingCount);

    this->cmdResponse_out(opCode, cmdSeq, Fw::CmdResponse::OK);
}

}  // namespace HiNamespace