#include "worldpacket.h"

WorldPacket::WorldPacket(quint8 opcode) : WorldBuffer(&m_packet, QIODevice::WriteOnly)
{
    m_opcode = opcode;
    *this << GetOpcodeHeader(m_opcode);
}
